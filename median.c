/* Author: Jinxin Yang
 * DP: get the median of two sorted array
 * X[0...n-1], Y[0...n-1]
 * I changed [1...n] to [0...n-1] to the
 * convenience of C programming
 */

int median(int X[], int Y[], int n) {
  if (n == 1) { // recursive rollback point
    if (x[0] < y[0]) {
      return x[0];
    } else if (x[0] == y[0]) { // if same, get mean
      return (x[0] + y[0]) / 2.0;
    } else {
      return y[0];
    }
  }

  int m = n/2, i;

  if (n%2 == 1) { // n is odd
    if (X[m] < Y[m]) { // abandon first half of X
      for(i=0; i<m+1; i++)
        X[i] = X[m+i];
      median(X, Y, m+1);
    } else { // abandon first half of Y
      for(i=0; i<m+1; i++)
        Y[i] = Y[m+i];
      median(X, Y, m+1);
    }
  } else { // n is even
    if(X[m-1] < Y[m-1]) { // abandon first half of X
      for(i=0; i<m; i++)
        X[i] = X[m+i];
      median(X, Y, m);
    } else { // abandon first half of Y
      for(i=0; i<m; i++)
        Y[i] = Y[m+i];
      median(X, Y, m);
    }
  }
}
