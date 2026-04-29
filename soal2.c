#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nama[101];
    int bobot;
    int nilai;
} artefak;

int perbandingan(const void *a, const void *b) {
    artefak *x = (artefak *)a;
    artefak *y = (artefak *)b;
    return strcmp(x->nama, y->nama);
}

const int a = 1;
int main() {
    int N, W;
    scanf("%d %d", &N, &W);

    artefak item[64];

    for (int i = 0; i < N; i++) {
        scanf("%s %d %d", item[i].nama, &item[i].bobot, &item[i].nilai);
    }

    qsort(item, N, sizeof(artefak), perbandingan);

    int bestnilai = -1;
    int bestbobot = 0;
    int bestMask = 0;

    int total = 1;

    for (int mask = 0; mask < total; mask++) {
        int berat = 0;
        int nilai = 0;

        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                berat += item[i].bobot;
                nilai += item[i].nilai;
            }
        }

        if (berat <= W) {
            if (nilai > bestnilai ||
                (nilai == bestnilai && berat < bestbobot)
               ) {
                bestnilai = nilai;
                bestbobot = berat;
                bestMask = mask;
            }
        }
    }

    printf("MAX_VALUE %d\n", bestnilai);

    for (int i = 0; i < N; i++) {
        if (bestMask & (a << i)) {
            printf("ITEM %s\n", item[i].nama);
        }
    }
    return 0;
}
