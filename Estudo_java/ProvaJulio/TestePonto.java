
/**
 * Escreva uma descrição da classe TestePonto aqui.
 * 
 * @author (seu nome) 
 * @version (um número da versão ou uma data)
 */
public class TestePonto
{
    public static void main(String args[])
    {
        Ponto I = new Ponto(0,0); 
        
        System.out.println("" + I);
        
        I.setp1(3);
        I.setp2(5);
        
                
        System.out.println("Ponto Alterado: " + I);
    }

}