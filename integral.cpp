#include <iostream>
#include <cmath>
#include <functional>
#include <iomanip>
using namespace std;
const double tolerancia = 1e-6;
const double pi = M_PI;

double computar_soma_Riemann(function<double(double)> funcao, double a, double b, double dx){

    double somatorio = 0.0;
    for(double x = a; x<b; x+=dx){
       somatorio += funcao(x)*dx;
    }

    return somatorio;
}

void testar_funcao(function<double(double)> funcao, double a, double b, double dx, double esperado, string nome_funcao){

    double resultado = computar_soma_Riemann(funcao, a, b, dx);
    if(abs(resultado-esperado)<tolerancia) cout << "Teste para " << nome_funcao << " PASSOU" << endl;
    else cout << "Teste para funcao " << nome_funcao << " FALHOU" << endl;
    cout << setprecision(10) << "Resultado obtido: " << resultado << "\nResultado esperado: " << setprecision(10) << esperado;
    cout << endl << "------------------------------------------------------" << endl << endl;
}






int main(){


    //funcoes predefinidas e testes unitarios
    auto funcao_logaritmo_natural = [](double x){return log(x); };
    auto funcao_raiz_quadrada = [](double x){return sqrt(x); };
    auto funcao_cosseno = [](double x){return cos(x); };
    auto funcao_seno = [](double x){return sin(x); };
    auto funcao_impar_intervalo_simetrico = [](double x){return pow(x, 5) - pow(x, 3) + 7*x; };
    auto funcao_exponencial = [](double x){return pow(2, x); };
    auto funcao_linear = [](double x){ return 2*x; };
    auto funcao_quadratica = [](double x){ return x*x + 1; };
    auto funcao_polinomial = [](double x){ return pow(x, 5) + 2*pow(x, 4) + pow(x, 2); };
    auto funcao_racional = [](double x){return 1 / (1+x); };


    testar_funcao(funcao_quadratica, 0, 4, 1e-7, 76.0/3.0, "funcao quadratica");
    testar_funcao(funcao_linear, -1, 3, 1e-7, 8.0, "funcao linear");
    testar_funcao(funcao_raiz_quadrada, 3, 6, 1e-7, 4*sqrt(6)-2*sqrt(3), "funcao raiz quadrada");
    testar_funcao(funcao_impar_intervalo_simetrico, -3, 3, 1e-7, 0.0, "funcao impar em intervalo simetrico");
    testar_funcao(funcao_seno, pi/2, pi, 1e-7, 1.0, "funcao seno");
    testar_funcao(funcao_cosseno, 0, 3*pi/2, 1e-7, -1.0, "funcao cosseno");
    testar_funcao(funcao_logaritmo_natural, 1.0, 4.0, 1e-7, 4*log(4)-3, "funcao logaritmo natural");
    testar_funcao(funcao_racional, 0, 2, 1e-7, log(3), "funcao racional");
    testar_funcao(funcao_polinomial, -1, 3, 1e-8, 3424.0/15.0, "funcao polinomial");
    testar_funcao(funcao_exponencial, 3, 5, 1e-8, 24/log(2), "funcao exponencial");





    return 0;
}

