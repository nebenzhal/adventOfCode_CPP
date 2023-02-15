#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int part1(std::vector<std::vector<const char *>> &checkingPath, const int &mapSize, int &yLoc, int &xLoc)
{
  for (int i = xLoc + 1; i < mapSize; ++i)
  { // forward check, xAxis
    if ((*checkingPath[1][i] - *checkingPath[1][xLoc]) < 0)
      continue;
    else
      goto check2;
  }
  return 1;
check2:
  for (int i = xLoc - 1; i >= 0; --i)
  { // back check, xAxis
    if (*checkingPath[1][i] - *checkingPath[1][xLoc] < 0)
      continue;
    else
      goto check3;
  }
  return 1;
check3:
  for (int i = yLoc + 1; i < mapSize; ++i)
  { // forward check, yAxis
    if (*checkingPath[0][i] - *checkingPath[0][yLoc] < 0)
      continue;
    else
      goto check4;
  }
  return 1;
check4:
  for (int i = yLoc - 1; i >= 0; --i)
  { // back check, yAxis
    if (*checkingPath[0][i] - *checkingPath[0][yLoc] < 0)
      continue;
    else
      return 0;
  }
  return 1;
}

int main()
{
  static std::string fileName = "input8.txt";
  std::fstream input(fileName);
  std::string tempStr;

  static std::vector<std::string> heightMap;

  while (getline(input, tempStr))
  {
    heightMap.push_back(tempStr);
  }

  const int mapSize = heightMap.size();

  int total = (mapSize * 2) + ((mapSize - 2) * 2);

  std::vector<std::vector<const char *>> checkingPath(2, std::vector<const char *>(mapSize, nullptr));

  for (int y = 1; y < (mapSize - 1); ++y) // go over each vertical line
  {
    for (int i = 0; i < mapSize; ++i)
    { // add current vert line to checkingPath
      checkingPath[0][i] = &heightMap[i][y];
    }
    for (int x = 1; x < (mapSize - 1); ++x) // go over each xVal within a constant verticalLine
    {
      for (int i = 0; i < mapSize; ++i)
      {                                        // add current horz line to checkingPath
        checkingPath[1][i] = &heightMap[x][i]; // checkingPath[1][i] = wStr.c_str(); diff ($time) seems to be 7800% (time)
      }
      total += part1(checkingPath, mapSize, x, y);
    }
  }
  std::cout << total << '\n';
}