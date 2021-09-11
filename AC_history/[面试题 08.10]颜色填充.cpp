// 编写函数，实现许多图片编辑软件都支持的「颜色填充」功能。
//
// 待填充的图像用二维数组 image 表示，元素为初始颜色值。初始坐标点的横坐标为 sr 纵坐标为 sc。需要填充的新颜色为 newColor 。 
//
// 「周围区域」是指颜色相同且在上、下、左、右四个方向上存在相连情况的若干元素。 
//
// 请用新颜色填充初始坐标点的周围区域，并返回填充后的图像。 
//
// 
//
// 示例： 
//
// 输入：
//image = [
// [1,1,1],
// [1,1,0],
// [1,0,1]
// ]
//
//sr = 1, sc = 1, newColor = 2
//输出：[
// [2,2,2],
// [2,2,0],
// [2,0,1]
// ]
//解释: 
//初始坐标点位于图像的正中间，坐标 (sr,sc)=(1,1) 。
//初始坐标点周围区域上所有符合条件的像素点的颜色都被更改成 2 。
//注意，右下角的像素没有更改为 2 ，因为它不属于初始坐标点的周围区域。
// 
//
// 
//
// 提示： 
//
// 
// image 和 image[0] 的长度均在范围 [1, 50] 内。 
// 初始坐标点 (sr,sc) 满足 0 <= sr < image.length 和 0 <= sc < image[0].length 。 
// image[i][j] 和 newColor 表示的颜色值在范围 [0, 65535] 内。 
// 
// Related Topics 深度优先搜索 
// 👍 22 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int direction[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    void dfs(vector<vector<int>> &image, int si, int sj, int oriColor, int newColor)
    {
        if(si < 0 ||si >= image.size() ||sj < 0 || sj >= image[0].size() ||image[si][sj] != oriColor) return;
        image[si][sj] = newColor;
        for (int i = 0; i < 4; ++i)
        {
            dfs(image, si + direction[i][0], sj + direction[i][1], oriColor, newColor);
        }
    }
    // 注意需要你改变的像素值需要你自己获取的
    // 而且原始颜色可能和要改变的颜色相同
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int oriColor = image[sr][sc];
        if(oriColor == newColor) return image; // 这个位置是这个题的核心坑
        dfs(image, sr, sc, oriColor, newColor);
        return image;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
