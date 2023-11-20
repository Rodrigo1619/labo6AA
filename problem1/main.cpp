#include <iostream>

using namespace std;

const int MAX_N = 1005; // maximo numero de actores
const int MAX_B = 105;  // maximo presupuesto

int maxPrestigio(int presupuesto, int numActores, int prestigio[], int salario[]) {
    int dp[MAX_N][MAX_B] = {0};

    // con lo siguiente vamos a ir llenando la matriz dp
    for (int i = 1; i <= numActores; ++i) {
        for (int j = 0; j <= presupuesto; ++j) {
            if (salario[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - salario[i - 1]] + prestigio[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    //retorno el valor maximo de presitigio que se puede obtener
    return dp[numActores][presupuesto];
}

int main() {
    int casos;
    cout << "Introduce el numero de casos: ";
    cin >> casos;

    while (casos--) {
        int presupuesto, numActores;
        cout << "Introduce el presupuesto: ";
        cin >> presupuesto;

        cout<<"Introduce el numero de actores: ";
        cin >>numActores;

        int prestigio[MAX_N], salario[MAX_N];

        for (int i = 0; i < numActores; ++i) {
            cout << "Introduce el prestigio del actor " << i+1 << ": ";
            cin >> prestigio[i];
            cout << "Introduce el salario del actor " << i+1 << ": ";
            cin >> salario[i];
        }

        int resultado = maxPrestigio(presupuesto, numActores, prestigio, salario);

        cout << "El máximo prestigio que puedes obtener es: " << resultado << endl;
    }

    return 0;
}