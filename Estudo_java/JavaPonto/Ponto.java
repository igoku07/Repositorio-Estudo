
public class Ponto
{
    // variáveis de instância - substitua o exemplo abaixo pelo seu próprio
    private int x;
    private int y;

    //isso representa o ponto central do circulo
    public Ponto(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public int getX()
    {
        return this.x;
    }
    
    public int getY()
    {
        return this.y;
    }
    
     public void setY(int Yps)
    {
        this.y = Yps;
    }
    
    public void setX(int Xis)
    {
        this.x = Xis;
    }
    
    public String toString()
    {
        return x + "" + y ;
    }
    
}