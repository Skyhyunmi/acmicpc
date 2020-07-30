#include <iostream>
#include <string>
using namespace std;
int main(void)
{
   int T;
   cin >> T;

   for (int k = 0; k < T; k++) {
      int N; cin >> N;
      char arr[2][51];
      int result[51][51] = { 0, };
      for (int i = 0; i < N; i++) {
         cin >> arr[0][i];
      }
      for (int i = 0; i < N; i++) {
         cin >> arr[1][i];
      }

      for (int i = 0; i < N; i++) {
         result[i][i] = 1;
         if ((i - 1 >= 0) && arr[0][i - 1] == 'Y' && arr[1][i] == 'Y') {
            result[i][i - 1] = 1;
            for (int j = i - 1; j >= 0; j--) {
               if (j < 0) break;
               if (arr[1][j] == 'Y' && j - 1 >= 0 && arr[0][j - 1] == 'Y')
                  result[i][j - 1] = 1;
               else break;
            }
         }
         if ((i + 1) < N && arr[0][i + 1] == 'Y' && arr[1][i] == 'Y') {
            result[i][i + 1] = 1;
            for (int j = i + 1; j < N; j++) {
               if (arr[1][j] == 'Y' && j + 1 < N && arr[0][j + 1] == 'Y')
                  result[i][j + 1] = 1;
               else break;
            }
         }
      }

      cout << "Case #" << k + 1 << ":" << "\n";
      for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
            if (result[i][j] == 1) cout << "Y";
            else cout << "N";
         }
         cout << "\n";
      }
   }
   return 0;
}