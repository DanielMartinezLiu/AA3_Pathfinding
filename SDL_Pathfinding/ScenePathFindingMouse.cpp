#include "ScenePathFindingMouse.h"

using namespace std;

ScenePathFindingMouse::ScenePathFindingMouse()
{
	draw_grid = false;
	maze = new Grid("../res/maze.csv");
	mazeWithWeight = new Grid("../res/maze1.csv");

	pathDFS = new PathFindingDFS(maze);
	pathDijkstra = new PathFindingDijkstra(mazeWithWeight);
	pathGFS = new PathFindingGreedyBFS(maze);
	pathA = new PathFindingAStar(mazeWithWeight);

	loadTextures("../res/maze.png", "../res/coin.png");

	srand((unsigned int)time(NULL));

	Agent *agent = new Agent;
	agent->loadSpriteTexture("../res/soldier.png", 4);
	agent->setBehavior(new PathFollowing);
	agent->setTarget(Vector2D(-20,-20));
	agents.push_back(agent);

	// set agent position coords to the center of a random cell
	Vector2D rand_cell(-1,-1);
	while (!maze->isValidCell(rand_cell))
		rand_cell = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));
	agents[0]->setPosition(maze->cell2pix(rand_cell));

	// set the coin in a random cell (but at least 3 cells far from the agent)
	coinPosition = Vector2D(-1,-1);
	while ((!maze->isValidCell(coinPosition)) || (Vector2D::Distance(coinPosition, rand_cell)<3))
		coinPosition = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));

}

ScenePathFindingMouse::~ScenePathFindingMouse()
{
	if (background_texture)
		SDL_DestroyTexture(background_texture);
	if (coin_texture)
		SDL_DestroyTexture(coin_texture);

	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}


void ScenePathFindingMouse::update(float dtime, SDL_Event *event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_KEYDOWN:
		if (event->key.keysym.scancode == SDL_SCANCODE_SPACE)
			draw_grid = !draw_grid;
		break;
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			Vector2D startPos = maze->pix2cell(Vector2D(agents[0]->getPosition().x, agents[0]->getPosition().y));
			Vector2D cell = maze->pix2cell(Vector2D((float)(event->button.x), (float)(event->button.y)));

			if (maze->isValidCell(cell)) 
			{
				
				//pathDFS->resetNodes();
				//pathDFS->setStart(new Node(startPos.x, startPos.y, 1));
				//pathDFS->setGoal(new Node(cell.x, cell.y, 1));
				//pathDFS->InitFind();
		
				//pathDijkstra->resetNodes();
				//pathDijkstra->setStart(new Node(startPos.x, startPos.y, 1));
				//pathDijkstra->setGoal(new Node(cell.x, cell.y, 1));
				//pathDijkstra->InitFind();
				
				//pathGFS->resetNodes();
				//pathGFS->setStart(new Node(startPos.x, startPos.y, 1));
				//pathGFS->setGoal(new Node(cell.x, cell.y, 1));
				//pathGFS->InitFind();
				
				pathA->resetNodes();
				pathA->setStart(new Node(startPos.x, startPos.y, 1));
				pathA->setGoal(new Node(cell.x, cell.y, 1));
				pathA->InitFind();
			}
		}
		break;
	default:
		break;
	}
	agents[0]->update(dtime, event);

	
	//pathDFS->FindPath(agents[0], dtime);
	//pathDFS->RecoverPath(agents[0]);
	
	//pathDijkstra->FindPath(agents[0], dtime);
	//pathDijkstra->RecoverPath(agents[0]);

	//pathGFS->FindPath(agents[0], dtime);
	//pathGFS->RecoverPath(agents[0]);

	pathA->FindPath(agents[0], dtime);
	pathA->RecoverPath(agents[0]);

	// if we have arrived to the coin, replace it in a random cell!
	if ((agents[0]->getCurrentTargetIndex() == -1) && (maze->pix2cell(agents[0]->getPosition()) == coinPosition))
	{
		coinPosition = Vector2D(-1, -1);
		while ((!maze->isValidCell(coinPosition)) || (Vector2D::Distance(coinPosition, maze->pix2cell(agents[0]->getPosition()))<3))
			coinPosition = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));
	}
	
}

void ScenePathFindingMouse::draw()
{
	drawMaze(mazeWithWeight);
	drawCoin();

	//pathDFS->draw();
	//pathDijkstra->draw();
	//pathGFS->draw();
	pathA->draw();

	if (draw_grid)
	{
		SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 255, 255, 255, 127);
		for (int i = 0; i < SRC_WIDTH; i+=CELL_SIZE)
		{
			SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), i, 0, i, SRC_HEIGHT);
		}
		for (int j = 0; j < SRC_HEIGHT; j = j += CELL_SIZE)
		{
			SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), 0, j, SRC_WIDTH, j);
		}
	}

	agents[0]->draw();
}

const char* ScenePathFindingMouse::getTitle()
{
	return "SDL Path Finding :: PathFinding Mouse Demo";
}

void ScenePathFindingMouse::drawMaze(Grid* _grid)
{
	SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 0, 155, 255, 255);

	for (int j = 0; j < _grid->getNumCellY(); j++)
	{
		for (int i = 0; i < _grid->getNumCellX(); i++)
		{		
			Vector2D pos = _grid->cell2pix(Vector2D(i, j));

			if (!_grid->isValidCell(Vector2D((float)i, (float)j)))
			{
				setColor(97, 97, 97, pos);

			} 
			else
			{
				switch (_grid->getTerrain(new Vector2D(i, j)))
				{
				case 1:
					setColor(168, 230, 163, pos);
					break;
				case 2:
					setColor(255, 245, 157, pos);
					break;
				case 3:
					setColor(255, 204, 128, pos);
					break;
				case 4:
					setColor(239, 154, 154, pos);
					break;
				default:
					break;
				}
			}
		}
	}
	//Alternative: render a backgroud texture:
	//SDL_RenderCopy(TheApp::Instance()->getRenderer(), background_texture, NULL, NULL );
}

void ScenePathFindingMouse::drawCoin()
{
	Vector2D coin_coords = maze->cell2pix(coinPosition);
	int offset = CELL_SIZE / 2;
	SDL_Rect dstrect = {(int)coin_coords.x-offset, (int)coin_coords.y - offset, CELL_SIZE, CELL_SIZE};
	SDL_RenderCopy(TheApp::Instance()->getRenderer(), coin_texture, NULL, &dstrect);
}

void ScenePathFindingMouse::setColor(int r, int g, int b, Vector2D pos)
{
	SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), r, g, b, 255);
	Vector2D coords = pos - Vector2D((float)CELL_SIZE / 2, (float)CELL_SIZE / 2);
	SDL_Rect rect = { (int)coords.x, (int)coords.y, CELL_SIZE, CELL_SIZE };
	SDL_RenderFillRect(TheApp::Instance()->getRenderer(), &rect);
}

bool ScenePathFindingMouse::loadTextures(char* filename_bg, char* filename_coin)
{
	SDL_Surface *image = IMG_Load(filename_bg);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	background_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	if (image)
		SDL_FreeSurface(image);

	image = IMG_Load(filename_coin);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	coin_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	if (image)
		SDL_FreeSurface(image);

	return true;
}
