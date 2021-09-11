//请你设计一个 贪吃蛇游戏，该游戏将会在一个 屏幕尺寸 = 宽度 x 高度 的屏幕上运行。如果你不熟悉这个游戏，可以 点击这里 在线试玩。 
//
// 起初时，蛇在左上角的 (0, 0) 位置，身体长度为 1 个单位。 
//
// 你将会被给出一个 (行, 列) 形式的食物位置序列。当蛇吃到食物时，身子的长度会增加 1 个单位，得分也会 +1。 
//
// 食物不会同时出现，会按列表的顺序逐一显示在屏幕上。比方讲，第一个食物被蛇吃掉后，第二个食物才会出现。 
//
// 当一个食物在屏幕上出现时，它被保证不能出现在被蛇身体占据的格子里。 
//
// 对于每个 move() 操作，你需要返回当前得分或 -1（表示蛇与自己身体或墙相撞，意味游戏结束）。 
//
// 示例： 
//
// 给定 width = 3, height = 2, 食物序列为 food = [[1,2],[0,1]]。
//
//Snake snake = new Snake(width, height, food);
//
//初始时，蛇的位置在 (0,0) 且第一个食物在 (1,2)。
//
//|S| | |
//| | |F|
//
//snake.move("R"); -> 函数返回 0
//
//| |S| |
//| | |F|
//
//snake.move("D"); -> 函数返回 0
//
//| | | |
//| |S|F|
//
//snake.move("R"); -> 函数返回 1 (蛇吃掉了第一个食物，同时第二个食物出现在位置 (0,1))
//
//| |F| |
//| |S|S|
//
//snake.move("U"); -> 函数返回 1
//
//| |F|S|
//| | |S|
//
//snake.move("L"); -> 函数返回 2 (蛇吃掉了第二个食物)
//
//| |S|S|
//| | |S|
//
//snake.move("U"); -> 函数返回 -1 (蛇与边界相撞，游戏结束)
// 
// Related Topics 设计 队列 
// 👍 31 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
//leetcode submit region end(Prohibit modification and deletion)
