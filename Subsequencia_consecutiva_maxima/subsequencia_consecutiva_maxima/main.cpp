
/* NÃO MODIFIQUE ESTE ARQUIVO! */

#include <iostream>
#include <ctime>
#include <list>
#include <cstdlib>

using namespace std;

float* vetor_aleatorio(int semente, int tamanho)
{
   srand(semente);
   float *v = new float[tamanho];
   for (int i = 0; i < tamanho; i++)
      v[i] = (float) rand() / (RAND_MAX/2.0) - 1;
   return v;
}

//      v[0]      v[1]      v[2] ...  v[tam-1]
// s[0]      s[1]      s[2]      ...           s[tam]
float* somas_acumuladas(float v[], int tamanho)
{
   float *s = new float[tamanho+1];
   s[0] = 0;
   for (int i = 1; i <= tamanho; i++)
      s[i] = s[i-1] + v[i-1];
   return s;
}

void avalia(string nome, float (*f)(float*,int), float v[], int n, double tempo_esperado)
{
   clock_t begin = clock();
   cout << nome << (*f)(v,n) << ", ";
   clock_t end = clock();
   double tempo = double(end - begin) / CLOCKS_PER_SEC;
   if ((tempo >= tempo_esperado/3.16) && (tempo <= 3.16*tempo_esperado))
      cout << "Tempo: " << tempo_esperado << "s" << endl;
   else cout << "Tempo fora da faixa prevista: " << tempo << "s" << endl;
}

float scm_forca_bruta(float S[], int n);
float scm_divisao_conquista(float S[], int n);
float scm_iterativo(float S[], int n);

int main()
{
   int semente, n; double tempo_fb, tempo_dc, tempo_iter;
   cin >> semente; cin >> n; cin >> tempo_fb; cin >> tempo_dc; cin >> tempo_iter;

   float *v = vetor_aleatorio(semente, n);
   float *s = somas_acumuladas(v, n);
   
   avalia("Forca bruta: ", &scm_forca_bruta, s, n, tempo_fb);
   avalia("Divisao e conquista: ", &scm_divisao_conquista, s, n, tempo_dc);
   avalia("Recursao de cauda (iterativo): ", &scm_iterativo, s, n, tempo_iter);
   
   delete[] v; delete[] s;
}
