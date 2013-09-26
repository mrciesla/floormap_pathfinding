void clean_up(Game &game)
{
	for (int i = 0; i < game.num_floors; ++i)
    for (int j = 0; j < game.size_floors; ++j) 
    	delete [] game.map[i][j];
}