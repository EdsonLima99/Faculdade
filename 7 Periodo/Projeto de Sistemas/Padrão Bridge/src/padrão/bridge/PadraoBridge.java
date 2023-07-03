package padrão.bridge;

import Dados.Circulo;
import Dados.Cor;
import Dados.CorAzul;
import Dados.CorVermelho;
import Dados.Forma;
import Dados.Quadrado;

public class PadraoBridge {

    public static void main(String[] args) {
        Cor corVermelho = new CorVermelho();
        Cor corAzul = new CorAzul();

        Forma quadradoVermelho = new Quadrado(corVermelho);
        quadradoVermelho.desenhar();

        Forma circuloAzul = new Circulo(corAzul); 
        circuloAzul.desenhar();
    }
    
}
