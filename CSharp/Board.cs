using Algorithm;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Text;

namespace Algorithm
{
    class Board
    {
        public TileType[,] Tile { get; private set; }
        public int Size { get; private set; }
        const char CIRCLE = '\u25cf';
        public int DestY { get ; private set; }
        public int DestX { get ; private set; }

        Player _player;

        public enum TileType
        {
            Empty,
            Wall,
            Player,
            Dest
        }

        public void Initialize(int size, Player player)
        {
            if (size % 2 == 0) return;
            _player = player;

            Tile = new TileType[size, size];
            Size = size;

            DestY = Size - 2;
            DestX = Size - 2;

            //GenerateByBinaryTree();
            GenerateBySideWinder();
        }
        void GenerateByBinaryTree()
        {
            // 길을 다 막아
            for (int y = 0; y < Size; y++)
            {
                for (int x = 0; x < Size; x++)
                {
                    if (x % 2 == 0 || y % 2 == 0)
                        Tile[y, x] = TileType.Wall;
                    else
                        Tile[y, x] = TileType.Empty;
                }
            }
            // 랜덤으로 길뚫어 (Binary Tree Algorithm)
            Random rand = new Random();

            for (int y = 0; y < Size; y++)
            {
                for (int x = 0; x < Size; x++)
                {
                    if (x % 2 == 0 || y % 2 == 0) continue;
                    if (x == Size - 2 && y == Size - 2) continue;
                    if (y == Size - 2)
                    {
                        if (rand.Next(0, 2) == 0)
                            continue;
                        Tile[y, x + 1] = TileType.Empty;
                        continue;
                    }
                    if (x == Size - 2)
                    {
                        if (rand.Next(0, 2) == 0)
                            continue;
                        Tile[y + 1, x] = TileType.Empty;
                        continue;
                    }

                    if (rand.Next(0, 2) == 0)
                    {
                        Tile[y, x + 1] = TileType.Empty;
                    }
                    else
                    {
                        Tile[y + 1, x] = TileType.Empty;
                    }
                }
            }
        }
        void GenerateBySideWinder()
        {
            // 길을 다 막아
            for (int y = 0; y < Size; y++)
            {
                for (int x = 0; x < Size; x++)
                {
                    if (x % 2 == 0 || y % 2 == 0)
                        Tile[y, x] = TileType.Wall;
                    else
                        Tile[y, x] = TileType.Empty;
                }
            }
            // 랜덤으로 길뚫어 (Binary Tree Algorithm)
            Random rand = new Random();

            for (int y = 0; y < Size; y++)
            {
                int count = 1;
                for (int x = 0; x < Size; x++)
                {
                    if (x % 2 == 0 || y % 2 == 0) continue;

                    if (x == Size - 2 && y == Size - 2) continue;
                    if (y == Size - 2)
                    {
                        //if (rand.Next(0, 2) == 0)
                        //    continue;
                        Tile[y, x + 1] = TileType.Empty;
                        continue;
                    }
                    if (x == Size - 2)
                    {
                        //if (rand.Next(0, 2) == 0)
                        //    continue;
                        Tile[y + 1, x] = TileType.Empty;
                        continue;
                    }

                    if (rand.Next(0, 2) == 0)
                    {
                        Tile[y, x + 1] = TileType.Empty;
                        count++;
                    }
                    else
                    {
                        int RandomIndex = rand.Next(0, count);
                        Tile[y+1, x - RandomIndex*2] = TileType.Empty;
                        count = 1;
                    }


                }
            }
        }
        public void Render()
        {
            ConsoleColor prevColor = Console.ForegroundColor;
            for (int y = 0; y < Size; y++)
            {
                for (int x = 0; x < Size; x++)
                {
                    // 플레이어
                    if (y == _player.PosY && x == _player.PosX)
                        Console.ForegroundColor = GetTileColor(TileType.Player);
                    else if (y == DestY && x == DestX)
                        Console.ForegroundColor = GetTileColor(TileType.Dest);
                    else
                        Console.ForegroundColor = GetTileColor(Tile[y, x]);

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
                case TileType.Player:
                    return ConsoleColor.Blue;
                case TileType.Dest:
                    return ConsoleColor.Yellow;
                default:
                    return ConsoleColor.Green;

            }
        }
    }
}
