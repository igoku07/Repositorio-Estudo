
/**
 * Escreva uma descrição da classe TesteReta aqui.
 * 
 * @author (seu nome) 
 * @version (um número da versão ou uma data)
 */
public class TesteReta
{
    //
    public static void main(String args[])
    {
        //Ponto instanciado
        Ponto P = new Ponto(5,5);
        Ponto I = new Ponto(10,10);
        
        
        //quero ver meus pontos
        System.out.println("\n" + P);
        System.out.println("" + I + "\n");
        
        //Inicio da reta
        Reta R = new Reta(P,I);
        Reta T = new Reta(I,P);
        System.out.println("No formato y = mx + b :\n" + T + "\n");
        
        double Qs = R.calcularM();
        double Q = R.calcularB(Qs);
        System.out.println("M = " + Qs + "");
        System.out.println("B = " + Q + "\n");
    }
}