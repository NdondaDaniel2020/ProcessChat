
int main() 
{
    const char *name = "Nd Daniel";
    const char *sms = "Um computador quântico é um dispositivo que executa cálculos fazendo uso direto de propriedades da mecânica quântica, tais como sobreposição e interferência. Teoricamente, computadores quânticos podem ser implementados e o mais desenvolvido atualmente, o D-Wave Two, trabalha com 512 qubits de informação. O principal ganho desses computadores é a possibilidade de resolver algoritmos num tempo eficiente, alguns problemas que na computação clássica levariam tempo impraticável (exponencial no tamanho da entrada), como por exemplo, a fatoração em primos de números naturais. A redução do tempo de resolução deste problema possibilitaria a quebra da maioria dos sistemas de criptografia usados atualmente. Contudo, o computador quântico ofereceria um novo esquema de canal mais seguro. Computadores quânticos são diferentes de computadores clássicos tais como computadores de DNA e computadores baseados em transístores, ainda que estes utilizem alguns efeitos da mecânica quântica.";
    
    char *formatted_message = format_message(name, sms);
    if (formatted_message) {
        printf("%s", formatted_message);
        free(formatted_message); // Libera a memória alocada
    }

    return 0;
}
