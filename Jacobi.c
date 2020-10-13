void Jacobi(double **a, int row, int col, double e, double *b, double *y)
{
    double *x = (double *)malloc(sizeof(double) * row);
    memset(x, 0, sizeof(sizeof(double) * row));

    double sum = 0;
    int cnt = 0;
    int i = 0;

    while(1)
    {
        for(i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
                sum += a[i][j] * x[j];

            sum = sum - x[i] * a[i][i];
            y[i] = (b[i] - sum) / a[i][i];
            sum = 0;
        }

        i = 0;

        while(i<row)
        {
            if(fabs(x[i] - y[i]) > e)
                break;
            ++i;
        }

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
