else if (weight[i] <= w) //weight of ith object is less than allowed weight thn
            k[i][w] = max( k[i-1][w] , profit[i] + k[i-1][w -weight[i]]);

            else
            k[i][w] = k[i-1][w];
            