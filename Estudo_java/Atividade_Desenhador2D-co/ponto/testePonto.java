package ponto;


/**
 * Escreva uma descrição da classe testePonto aqui.
 * 
 * @author (seu nome) 
 * @version (um número da versão ou uma data)
 */
public class testePonto
{
    public static void main()
    {
        //
        Ponto P = new Ponto();
        
        P.setX(10);
        P.setY(0);
        
        System.out.println("" + P);
        Ponto J = new Ponto(10,10);
        
        double D;
        
        D = J.calcularDistancia(P);
        
        System.out.println("" + D);
    }
}