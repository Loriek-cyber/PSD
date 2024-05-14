typedef struct stock *Stock;
Stock InitStock(int value, int giorno, int mese, int anno, int ora, int minuto, int secondi);
int gValue(Stock s);
int *gData(Stock s); 