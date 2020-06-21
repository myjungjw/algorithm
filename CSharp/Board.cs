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
            if (size % 2 == 0) return;

            _tile = new TileType[size, size];
            _size = size;

            //GenerateByBinaryTree();
            //GenerateBySideWinder();
        }
        void GenerateByBinaryTree()
        {
            // 길을 다 막아
            for (int y = 0; y < _size; y++)
            {
                for (int x = 0; x < _size; x++)
                {
                    if (x % 2 == 0 || y % 2 == 0)
                        _tile[y, x] = TileType.Wall;
                    else
                        _tile[y, x] = TileType.Empty;
                }
            }
            // 랜덤으로 길뚫어 (Binary Tree Algorithm)
            Random rand = new Random();

            for (int y = 0; y < _size; y++)
            {
                for (int x = 0; x < _size; x++)
                {
                    if (x % 2 == 0 || y % 2 == 0) continue;
                    if (x == _size - 2 && y == _size - 2) continue;
                    if (y == _size - 2)
                    {
                        if (rand.Next(0, 2) == 0)
                            continue;
                        _tile[y, x + 1] = TileType.Empty;
                        continue;
                    }
                    if (x == _size - 2)
                    {
                        if (rand.Next(0, 2) == 0)
                            continue;
                        _tile[y + 1, x] = TileType.Empty;
                        continue;
                    }

                    if (rand.Next(0, 2) == 0)
                    {
                        _tile[y, x + 1] = TileType.Empty;
                    }
                    else
                    {
                        _tile[y + 1, x] = TileType.Empty;
                    }
                }
            }
        }
        void GenerateBySideWinder()
        {
            // 길을 다 막아
            for (int y = 0; y < _size; y++)
            {
                for (int x = 0; x < _size; x++)
                {
                    if (x % 2 == 0 || y % 2 == 0)
                        _tile[y, x] = TileType.Wall;
                    else
                        _tile[y, x] = TileType.Empty;
                }
            }
            // 랜덤으로 길뚫어 (Binary Tree Algorithm)
            Random rand = new Random();

            for (int y = 0; y < _size; y++)
            {
                int count = 1;
                for (int x = 0; x < _size; x++)
                {

                    if (x % 2 == 0 || y % 2 == 0) continue;

                    if (x == _size - 2 && y == _size - 2) continue;
                    if (y == _size - 2)
                    {
                        if (rand.Next(0, 2) == 0)
                            continue;
                        _tile[y, x + 1] = TileType.Empty;
                        continue;
                    }
                    if (x == _size - 2)
                    {
                        if (rand.Next(0, 2) == 0)
                            continue;
                        _tile[y + 1, x] = TileType.Empty;
                        continue;
                    }

                    if (rand.Next(0, 2) == 0)
                    {
                        _tile[y, x + 1] = TileType.Empty;
                        count++;
                    }
                    else
                    {
                        int RandomIndex = rand.Next(0, count);
                        _tile[y+1, x - RandomIndex*2] = TileType.Empty;
                        count = 1;
                    }


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
