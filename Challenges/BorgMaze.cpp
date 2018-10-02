/*
    ID: 10307

    This one is TERRIBLE, please don't look at it.
    Really just needed to get it done.
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

#define Borgmaze std::vector<std::vector<char>>

struct MazePos {
    int i;
    int j;

};

int bfs(MazePos start, MazePos end, Borgmaze &maze, int x, int y)
{
    int distance = 0;
    bool visited[51][51] = {false};
    std::vector<std::vector<int>> dist(51, std::vector<int>(51));
    std::list<MazePos> queue;
    queue.push_back(start);
    visited[start.i][start.j] = true;
    while(!queue.empty()) 
    {
        ++distance;
        MazePos pos = queue.front();
        queue.pop_front();
        if(maze[pos.i - 1][pos.j] != '#' && !visited[pos.i - 1][pos.j])
        { 
            visited[pos.i - 1][pos.j] = true;
            dist[pos.i - 1][pos.j] = dist[pos.i][pos.j] + 1;
            MazePos newPos;
            newPos.i = pos.i - 1;
            newPos.j = pos.j;
            queue.push_back(newPos);
            if(pos.i - 1 == end.i && pos.j == end.j) return dist[pos.i - 1][pos.j];
        }
        if(maze[pos.i + 1][pos.j] != '#' && !visited[pos.i + 1][pos.j])
        { 
            visited[pos.i + 1][pos.j] = true;
            dist[pos.i + 1][pos.j] = dist[pos.i][pos.j] + 1;
            MazePos newPos;
            newPos.i = pos.i + 1;
            newPos.j = pos.j;
            queue.push_back(newPos);
            if(pos.i + 1 == end.i && pos.j == end.j) return dist[pos.i + 1][pos.j];
        }
        if(maze[pos.i][pos.j - 1] != '#' && !visited[pos.i][pos.j - 1])
        { 
            visited[pos.i][pos.j - 1] = true; 
            dist[pos.i][pos.j - 1] = dist[pos.i][pos.j] + 1;
            MazePos newPos;
            newPos.i = pos.i;
            newPos.j = pos.j - 1;
            queue.push_back(newPos);
            if(pos.i == end.i && pos.j - 1 == end.j) return dist[pos.i][pos.j - 1];
        }
        if(maze[pos.i][pos.j + 1] != '#' && !visited[pos.i][pos.j + 1])
        { 
            visited[pos.i][pos.j + 1] = true;    
            dist[pos.i][pos.j + 1] = dist[pos.i][pos.j] + 1;
            MazePos newPos;
            newPos.i = pos.i;
            newPos.j = pos.j + 1;
            queue.push_back(newPos);
            if(pos.i == end.i && pos.j + 1 == end.j) return dist[pos.i][pos.j + 1];
        }   
    }
    return 0;
}

//straight up stolen from geeekforgeeks out of desperation
struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 
    DisjointSets(int n) 
    { 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
            parent[i] = i; 
        } 
    } 

    int find(int u) 
    { 
        if (u != parent[u]) parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  
    void merge(int x, int y) 
    { 
        x = find(x);
        y = find(y); 
        if (rnk[x] > rnk[y]) parent[y] = x; 
        else parent[x] = y; 
  
        if (rnk[x] == rnk[y]) rnk[y]++; 
    } 
}; 


int main()
{
    std::vector<std::vector<char>> maze;
    std::vector<MazePos> aliens;
    std::string line;
    int cases; 
    std::cin >> cases;
    while(cases--)
    {
        int x, y;
        MazePos startPos;
        std::cin >> x >> y;
        getline(std::cin, line); //Getting rid of this line
        for(int i = 0; i < y; i++)
        {
            std::vector<char> row;
            getline(std::cin, line);
            for(size_t j = 0; j < line.length(); j++)
            {
                row.push_back(line[j]);
                if(line[j] == 'S')  //Find startposition
                {
                    startPos.i = i;
                    startPos.j = j;
                }
                if(line[j] == 'A')  //Find all the aliens for some reason
                {
                    MazePos alienPos;
                    alienPos.i = i;
                    alienPos.j = j;
                    aliens.push_back(alienPos);
                }
            } 
            maze.push_back(row);
        }
        std::vector<std::pair<int, std::pair<int, int>>> distances;
        for(size_t i = 0; i < aliens.size(); i++)
        {
            distances.push_back({bfs(startPos, aliens[i], maze, x, y), {0, i + 1}});
        }

        for(size_t i = 0; i < aliens.size(); i++)
        {
            for(size_t j = 0; j < aliens.size(); j++)
            {
                if(aliens[i].i == aliens[j].i && aliens[i].j == aliens[j].j) continue;
                distances.push_back({bfs(aliens[i], aliens[j], maze, x, y), {i + 1, j + 1}});
            }
        }   
        //straight up stolen from geeekforgeeks out of desperation
        int mst = 0;
        DisjointSets ds(distances.size());
        std::sort(distances.begin(), distances.end());
        for(auto it = distances.begin(); it != distances.end(); ++it)
        {
            int u = it->second.first;
            int v = it->second.second;
            int set_u = ds.find(u);
            int set_v = ds.find(v);
            if(set_u != set_v)
            {
                mst += it->first;
                ds.merge(set_u, set_v);
            }
        }
        std::cout << mst << "\n";
        maze.clear();
        aliens.clear();
        distances.clear();
    }
}