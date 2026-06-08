#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 8192

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Maneira de uso correto: %s <alvo>\n", argv[0]);
        return 1;
    }

    char domain[256];
    strncpy(domain, argv[1], sizeof(domain) - 1);
    domain[sizeof(domain) - 1] = '\0';

    printf("========================================\n");
    printf(" DNS Zone Transfer Scan\n");
    printf(" By igr0t\n");
    printf(" GitHub: https://github.com/igr0t\n");
    printf("========================================\n\n");

    char ns_cmd[512];
    snprintf(ns_cmd, sizeof(ns_cmd),
             "host -t ns %s 2>/dev/null",
             domain);

    FILE *ns_fp = popen(ns_cmd, "r");

    if (!ns_fp) {
        perror("popen");
        return 1;
    }

    char line[MAX_LINE];
    int found_ns = 0;

    while (fgets(line, sizeof(line), ns_fp)) {

        char ns[512];

        if (sscanf(line, "%*s name server %511s", ns) != 1)
            continue;

        found_ns = 1;

        size_t len = strlen(ns);
        if (len > 0 && ns[len - 1] == '.')
            ns[len - 1] = '\0';

        printf("\n========================================\n");
        printf("[+] Nameserver: %s\n", ns);
        printf("========================================\n");

        char axfr_cmd[1024];

        snprintf(axfr_cmd,
                 sizeof(axfr_cmd),
                 "dig AXFR %s @%s +noquestion +nocmd 2>/dev/null",
                 domain,
                 ns);

        FILE *axfr_fp = popen(axfr_cmd, "r");

        if (!axfr_fp) {
            printf("[-] Error [AXFR]\n");
            continue;
        }

        int lines = 0;

        while (fgets(line, sizeof(line), axfr_fp)) {

            if (strstr(line, "Transfer failed"))
                continue;

            if (strstr(line, "XFR size"))
                continue;

            printf("%s", line);
            lines++;
        }

        pclose(axfr_fp);

        if (lines == 0) {
            printf("[-] AXFR negado ou nenhuma resposta recebida.\n");
        } else {
            //printf("\n[+] log lines: %d\n", lines);
        }
    }

    pclose(ns_fp);

    if (!found_ns) {
        fprintf(stderr, "[-] Nenhum servidor para transferencia encontrado.\n");
        return 1;
    }


    return 0;
}




