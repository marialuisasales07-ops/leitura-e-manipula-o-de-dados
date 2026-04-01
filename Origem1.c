
#include <stdio.h>
#include <string.h>
#include <stdio.h>

//campo de um único estado
typedef struct {
	char sigla_tribunal[10];
	char procedimento[100];
	char ramo_justica[50];
	char sigla_grau[10];
	char uf_oj[5];
	char municipio_oj[100];

	unsigned int id_ultimo_oj;

	char nome[150];
	char mesano_cnm1[10];
	char mesano_sent[10];

	int casos_novos_2026;
	int julgados_2026;
	int prim_sent2026;
	int suspensos_2026;
	int dessobrestados_2026;
	int cumprimento_meta1;
	int distm2_a;
	int julgm2_a;
	int suspm2_a;
	int cumprimento_meta2a;
	int distm2_ant;
	int julgm2_ant;
	int suspm2_ant;
	int desom2_ant;
	int cumprimento_meta2ant;
	int distm4_a;
	int julgm4_a;
	int suspm4_a;
	int cumprimento_meta4a;
	int distm4_b;
	int julgm4_b;
	int suspm4_b;
	int cumprimento_meta4b;

}dados;

int main() {
	//objetivo:Colocar os dados em um único arquivo para melhorar a manipulação
	dados dados_arquivo;
	FILE* arq_destino = fopen("base_de_dados.csv", "w");
	char* estados[] = { "AC" ,"AL" ,"AM" ,"AP" ,"BA" ,
					"CE" ,"DF" ,"ES" ,"GO" ,"MA" ,
					"MG" ,"MS" ,"MT" ,"PA" ,"PB" ,
					"PE" ,"PI" ,"PR" ,"RJ" ,"RN" ,
					"RO" ,"RR" ,"RS" ,"SC" ,"SE" ,
					"SP" ,"TO"
	};
	fprintf(arq_destino, "sigla_tribunal,procedimento,ramo_justica,sigla_grau,uf_oj,municipio_oj,id_ultimo_oj,nome,mesano_cnm1,mesano_sent,casos_novos_2026,julgados_2026,prim_sent2026,suspensos_2026,dessobrestados_2026,cumprimento_meta1,distm2_a,julgm2_a,suspm2_a,cumprimento_meta2a,distm2_ant,julgm2_ant,suspm2_ant,desom2_ant,cumprimento_meta2ant,distm4_a,julgm4_a,suspm4_a,cumprimento_meta4a,distm4_b,julgm4_b,suspm4_b,cumprimento_meta4b\n");
	int i;
	for (i = 0;i < 27;i++) {
		char nome_arq_origem[100];
		snprintf(nome_arq_origem, sizeof(nome_arq_origem), "teste_TRE-%s.csv", estados[i]);
		FILE* arq_origem = fopen(nome_arq_origem, "r");
		if (arq_origem != NULL) {
			while (fscanf(arq_origem, " %[^,], %[^,], %[^,], %[^,], %[^,], %[^,],%u, %[^,], %[^,], %[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", dados_arquivo.sigla_tribunal, dados_arquivo.procedimento, dados_arquivo.ramo_justica, dados_arquivo.sigla_grau, dados_arquivo.uf_oj, dados_arquivo.municipio_oj, &dados_arquivo.id_ultimo_oj, dados_arquivo.nome, dados_arquivo.mesano_cnm1, dados_arquivo.mesano_sent, &dados_arquivo.casos_novos_2026, &dados_arquivo.julgados_2026, &dados_arquivo.prim_sent2026, &dados_arquivo.suspensos_2026, &dados_arquivo.dessobrestados_2026, &dados_arquivo.cumprimento_meta1, &dados_arquivo.distm2_a, &dados_arquivo.julgm2_a, &dados_arquivo.suspm2_a, &dados_arquivo.cumprimento_meta2a, &dados_arquivo.distm2_ant, &dados_arquivo.julgm2_ant, &dados_arquivo.suspm2_ant, &dados_arquivo.desom2_ant, &dados_arquivo.cumprimento_meta2ant, &dados_arquivo.distm4_a, &dados_arquivo.julgm4_a, &dados_arquivo.suspm4_a, &dados_arquivo.cumprimento_meta4a, &dados_arquivo.distm4_b, &dados_arquivo.julgm4_b, &dados_arquivo.suspm4_b, &dados_arquivo.cumprimento_meta4b) != EOF) {
				fprintf(arq_destino, " %s,%s,%s,%s,%s,%s,%u,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", dados_arquivo.sigla_tribunal, dados_arquivo.procedimento, dados_arquivo.ramo_justica, dados_arquivo.sigla_grau, dados_arquivo.uf_oj, dados_arquivo.municipio_oj, dados_arquivo.id_ultimo_oj, dados_arquivo.nome, dados_arquivo.mesano_cnm1, dados_arquivo.mesano_sent, dados_arquivo.casos_novos_2026, dados_arquivo.julgados_2026, dados_arquivo.prim_sent2026, dados_arquivo.suspensos_2026, dados_arquivo.dessobrestados_2026, dados_arquivo.cumprimento_meta1, dados_arquivo.distm2_a, dados_arquivo.julgm2_a, dados_arquivo.suspm2_a, dados_arquivo.cumprimento_meta2a, dados_arquivo.distm2_ant, dados_arquivo.julgm2_ant, dados_arquivo.suspm2_ant, dados_arquivo.desom2_ant, dados_arquivo.cumprimento_meta2ant, dados_arquivo.distm4_a, dados_arquivo.julgm4_a, dados_arquivo.suspm4_a, dados_arquivo.cumprimento_meta4a, dados_arquivo.distm4_b, dados_arquivo.julgm4_b, dados_arquivo.suspm4_b, dados_arquivo.cumprimento_meta4b);
			}
			fclose(arq_origem);
		}
		else {
			printf("Houve erro ao abrir o arquivo");
			continue;
		}


	}
	fclose(arq_destino);
	return 0;

}
