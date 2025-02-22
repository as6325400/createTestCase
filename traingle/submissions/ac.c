#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2, x3, y3;
    
    // 輸入三個點的座標
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    
    // 計算三角形面積
    double area = 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    
    // 無條件進位
    int result = (int)ceil(area);
    
    // 輸出結果
    printf("%d\n", result);
    
    return 0;
}
