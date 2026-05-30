import java.util.Scanner;
import javax.swing.*;

/**
 * Escreva uma descrição da classe App aqui.
 * 
 * @author (seu nome) 
 * @version (um número da versão ou uma data)
 */
public class App
{
    public static void main(String args[]){    
            //oque fazer no jogo?
            int Qtd = 2;
            int Passo = 2;
            JosephusRegras J = new JosephusRegras(10,10);
            J.setSize(270,340);
            J.setVisible( true );
    }
}