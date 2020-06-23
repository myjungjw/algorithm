using System;
using System.Collections.Generic;
using System.Drawing;
using System.Dynamic;
using System.IO.MemoryMappedFiles;
using System.Runtime.InteropServices.ComTypes;
using System.Text;

namespace Algorithm
{
    class Pos
    {
        public Pos(int y, int x) { Y = y; X = x; }
        public int Y;
        public int X;
    }
    class Player
    {
        public int PosY { get; private set; }
        public int PosX { get; private set; }
        Random _rand = new Random();
        Board _board;

        enum Dir
        {
            Up = 0,  
            Left = 1,  
            Down = 2, 
            Right = 3 
        }
        int _dir = (int)Dir.Up;
        List<Pos> _points = new List<Pos>();

        public void Initialize(int posY, int posX, Board board)
        {
            PosY = posY;
            PosX = posX;
            _board = board;

            BFS();
            // RightHand();
        }

        void BFS()
        {
            int[] deltaY = new int[] { -1, 0, 1, 0 };
            int[] deltaX = new int[] { 0, -1, 0, 1};

            bool[,] found = new bool[_board.Size, _board.Size];
            Pos[,] parent = new Pos[_board.Size, _board.Size];

            Queue<Pos> q = new Queue<Pos>();
            q.Enqueue(new Pos(PosY, PosX));
            found[PosY, PosX] = true;
            parent[PosY, PosX] = new Pos(PosY, PosX);

            while ( q.Count > 0)
            {
                Pos pos = q.Dequeue();
                int nowY = pos.Y;
                int nowX = pos.X;

                for ( int i = 0; i < 4; i++ )
                {
                    int nextY = nowY + deltaY[i];
                    int nextX = nowX + deltaX[i];

                    if (nextY < 0 || nextX < 0 || nextY >= _board.Size || nextX >= _board.Size) continue;
                    if (_board.Tile[nextY, nextX] == Board.TileType.Wall) continue;
                    if (found[nextY, nextX]) continue;

                    q.Enqueue(new Pos(nextY, nextX));
                    found[nextY, nextX] = true;
                    parent[nextY, nextX] = new Pos(nowY, nowX);
                }
            }

            int y = _board.DestY;
            int x = _board.DestX;

            while (parent[y, x].Y != y || parent[y, x].X != x) // 시작점이면 현재 위치가 parent 위치
            {
                _points.Add(new Pos(y, x));
                Pos pos = parent[y, x];
                y = pos.Y;
                x = pos.X;
            }
            _points.Add(new Pos(y, x));
            _points.Reverse();
        }

        void RightHand()
        {
            // 현재 방향이 ULDR0123 일 경우 front와 right 방향
            int[] frontY = new int[] { -1, 0, 1, 0 };
            int[] frontX = new int[] { 0, -1, 0, 1 };
            int[] rightY = new int[] { 0, -1, 0, 1 };
            int[] rightX = new int[] { 1, 0, -1, 0 };

            _points.Add(new Pos(PosY, PosX));
            while (PosY != _board.DestY || PosX != _board.DestX)
            {
                if (_board.Tile[PosY + rightY[_dir], PosX + rightX[_dir]] == Board.TileType.Empty)   // 우측회전 가능
                {
                    // 오른쪽 방향으로 회전
                    _dir = (int)((_dir + 3) % 4);
                    // 일보전진
                    PosY += frontY[_dir];
                    PosX += frontX[_dir];
                    _points.Add(new Pos(PosY, PosX));
                }
                else if (_board.Tile[PosY + frontY[_dir], PosX + frontX[_dir]] == Board.TileType.Empty) // 직진 가능
                {
                    // 일보전진
                    PosY += frontY[_dir];
                    PosX += frontX[_dir];
                    _points.Add(new Pos(PosY, PosX));
                }
                else
                {
                    // 왼쪽 방향으로 회전
                    _dir = (int)((_dir + 5) % 4);
                }
            }
        }

        const int MOVE_TICK = 40;
        int _sumTick = 0;
        int _lastIndex = 0;
        public void Update(int deltaTick)
        {
            if (_lastIndex >= _points.Count) return;
            _sumTick += deltaTick;
            if (_sumTick >= MOVE_TICK)
            {
                _sumTick = 0;

                PosY = _points[_lastIndex].Y;
                PosX = _points[_lastIndex].X;
                _lastIndex++;
            }
        }
    }
}
