
/**
 * Escreva uma descrição da classe Ponto aqui.
 * 
 * @author (seu nome) 
 * @version (um número da versão ou uma data)
 */
public class Ponto
{
    private double p1;
    private double p2;

    /**
     * Construtor para objetos da classe Ponto
     */
    public Ponto(double p1, double p2)
    {
        this.p1 = p1;
        this.p2 = p2;
    }
    
    public double getP1()
    {
        return this.p1;
    }
    
    public double getP2()
    {
        return this.p2;
    }
    

    public void setp1(double P1)
    {
        this.p1 = P1;
    }
        
    public void setp2(double P2)
    {
        this.p2 = P2;
    }
    
    public String toString()
    {
        return "X = " + this.p1 + " Y = " + this.p2;
    }
}
    
