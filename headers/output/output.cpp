#include "output.h"

using namespace std;

void saveLastScreenArray(char oldS[SCREENROWS][SCREENCOLS], char newS[SCREENROWS][SCREENCOLS])
{
	for (int i = 0; i < SCREENROWS; i++)
	{
		for (int j = 0; j < SCREENCOLS; j++)
		{
			oldS[i][j] = newS[i][j];
		}
	}
}

void saveLastMenuArray(char oldM[SCREENROWS][MENUCOLS], char newM[SCREENROWS][MENUCOLS])
{
	for (int i = 0; i < SCREENROWS; i++)
	{
		for (int j = 0; j < MENUCOLS; j++)
		{
			oldM[i][j] = newM[i][j];
		}
	}
}

void initSolid(char solide[SOLIDCOUNT])
{
	fstream fbe ("materials/solid.txt");
	
	for (int i = 0; i < SOLIDCOUNT; i++)
	{
		fbe>>solide[i];
	}
	
	fbe.close();
}

void initWalkable(char walkablee[WALKABLECOUNT])
{
	fstream fbe ("materials/walkable.txt");
	
	for (int i = 0; i < WALKABLECOUNT; i++)
	{
		fbe>>walkablee[i];
	}
	
	fbe.close();
}

void initWorld(map world[WORLDROWS][WORLDCOLS], char solide[SOLIDCOUNT], char walkablee[WALKABLECOUNT])
{
	char cahr;
	
	fstream fbe ("maps/world.txt");
	
	for (int i = 0; i < WORLDROWS; i++)
	{
		for (int j = 0; j < WORLDCOLS; j++)
		{
			fbe>>cahr;
			
			if (cahr == 'i' || cahr == '0')
			{
				world[i][j].texture = ' ';
			}
			else
			{
				world[i][j].texture = cahr;
			}
			
			world[i][j].solid = false;
			
			for (int k = 0; k <= SOLIDCOUNT; k++)
			{
				if (cahr == solide[k])
				{
					world[i][j].solid = true;
				}
			}
			
			world[i][j].walkable = false;
			
			for (int k = 0; k <= WALKABLECOUNT; k++)
			{
				if (cahr == walkablee[k])
				{
					world[i][j].walkable = true;
				}
			}
		}
	}
	
	fbe.close();
}