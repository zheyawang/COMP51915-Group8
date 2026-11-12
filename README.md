# Tic-Tac-Toe

## Authors:
| Username | Name |
|----------|------|
| zheyawang | Zheya Wang |
| Tannii0312 | Kanti Suwannasai |
| isla-zheng | Yingjia Zheng |


## Win Conditions:
- The board has 3 rows and 3 columns.
- There are two players: × and ○ .
- The × player moves first.
- Players take turns placing their symbol in an empty cell.
- Three matching symbols in a row, column, or diagonal win the game.
- The game ends as soon as a player wins.
- A full board with no winner is a draw.

## Build Instructions:
```bash
mkdir -p build_dir
cd build_dir
cmake ../
cmake --build .
```

## Starting the Game：
```bash
./tic_tac_toe
```

## Testing：
```bash
ctest --output-on-failure
```
