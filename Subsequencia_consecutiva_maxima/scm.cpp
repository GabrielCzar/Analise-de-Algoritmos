#include <algorithm>

using namespace std;

float scm_forca_bruta (float S[], int n ){
    float maior = 0;
    for (int i = 0; i <= n - 1; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (S[j] - S[i] > maior)
                maior = S[j] - S[i];
    return maior;
}

// Chamada recursiva considera do instante ini até o instante fim.
// Retorna menor valor (min), maior valor (max), e valor da scm no intervalo considerado.
struct STRUCT {
    float minimo;
    float maximo;
    float scm;

    STRUCT (float minimo, float maximo, float scm) {
        this->minimo = minimo; this->maximo = maximo; this->scm = scm;
    }
};

STRUCT scm_dc_rec (float S[], int ini, int fim) {
    float f = 0;
    if (ini + 1 == fim)
        return STRUCT (min (S[ini], S[fim]), max (S[ini], S[fim]), max (f, S[fim] - S[ini]));
    float meio = (ini + fim) / 2;
    STRUCT s1 = scm_dc_rec(S, ini, meio);
    STRUCT s2 = scm_dc_rec(S, meio, fim);
    float fb = s2.maximo - s1.minimo;
    return STRUCT (min (s1.minimo, s2.minimo), max (s1.maximo, s2.maximo), max (max (s1.scm, s2.scm), fb));
}

float scm_divisao_conquista (float S[], int n) {
    STRUCT s = scm_dc_rec(S, 0, n);
    return s.scm;
}

float scm_iterativo (float S[], int n) {
    float minimo = 0, scm = 0;
    for (int i = 1; i <= n; ++i) {
        scm = max(scm, S[i] - minimo);
        minimo = min(minimo, S[i]);
    }
    return scm;
}

