using Algorithm;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Text;

namespace Algorithm
{
    public enum TileType
    {
        Empty,
        Wall,
    }
    
    class Board
    {

        public TileType[,] _tile;
        public int _size;
        const char CIRCLE = '\u25cf';

        public void Initialize(int size)
        {
            _tile = new TileType[size, size];
            _size = size;

            for (int y = 0; y < _size; y++)
            {
                for ( int x = 0; x < _size; x++)
                {
                    if (x == 0 || x == size - 1 || y == 0 || y == size - 1)
                        _tile[y, x] = TileType.Wall;
                    else
                        _tile[y, x] = TileType.Empty; 
                }
            }
        }

        public void Render()
        {
            ConsoleColor prevColor = Console.ForegroundColor;
            for (int y = 0; y < _size; y++)
            {
                for (int x = 0; x < _size; x++)
                {
                    Console.ForegroundColor = GetTileColor(_tile[y, x]);
                    Console.Write(CIRCLE);
                }
                Console.WriteLine();
            }
            Console.ForegroundColor = prevColor;
        }
        ConsoleColor GetTileColor(TileType type)
        {
            switch (type)
            {
                case TileType.Empty:
                    return ConsoleColor.Green;
                case TileType.Wall:
                    return ConsoleColor.Red;
                default:
                    return ConsoleColor.Green;

            }
        }
    }
}
