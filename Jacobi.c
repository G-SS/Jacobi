/**
 * @brief Jacobi 雅可比迭代法
 * @param[in]  a 系数矩阵
 * @param[in]  row 矩阵行数
 * @param[in]  col 矩阵列数
 * @param[in]  e 精度
 * @param[in]  b
 * @param[out] y 解
 */
void Jacobi(double **a, int row, int col, double e, double *b, double *y)
{
    /// 初始向量
    double *x = (double *)malloc(sizeof(double) * row);
    memset(x, 0, sizeof(sizeof(double) * row));

    double sum = 0;
    int cnt = 0;        // 迭代计数   
    int i = 0;

    while(1)
    {
        /// 迭代
        for(i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
                sum += a[i][j] * x[j];

            sum = sum - x[i] * a[i][i];
            y[i] = (b[i] - sum) / a[i][i];
            sum = 0;
        }

        i = 0;

        /// 精度判断
        while(i<row)
        {
            if(fabs(x[i] - y[i]) > e)
                break;
            ++i;
        }
      
        /// 更新初始向量
        if(i != row)
        {
            for(i=0; i<row; ++i)
                x[i] = y[i];
            ++cnt;
        }
        else if(i == row)
            break;
    }
    for(i=0; i<row; ++i)
        cout << y[i] << "\t";
    cout << cnt << endl;

    free(x);
    x = NULL;

}
