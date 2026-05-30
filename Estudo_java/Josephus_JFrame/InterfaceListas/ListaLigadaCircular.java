/**
 * ListaLigadaCircular. Ed para Lista Ligada Circular
 * 
 * @author Guilherme Pequeneza 
 * @version 1.0 2023/05/15
 */
package InterfaceListas;
public class ListaLigadaCircular<T> implements IListaLigada<T>{
    No inicio, fim;
    int qtdNos;

    /**
     * ListaLigadaCircular Construtor
     *
     */
    public ListaLigadaCircular(){
        setInicio(null);
        setFim(null);
        setQtdNos(0);
    }

    /**
     * setInicio
     *
     * @param inicio No inicio da lista ligada
     */
    public void setInicio(No inicio){
        this.inicio = inicio;
    }

    /**
     * getInicio
     *
     * @return No de inicio da lista ligada
     */
    public No getInicio(){
        return(this.inicio);
    }

    /**
     * getFim
     *
     * @return No do final da lista ligada
     */
    public No getFim(){
        return(this.fim);
    }

    /**
     * setFim
     *
     * @param fim No fim da lista ligada
     */
    public void setFim(No fim){
        this.fim = fim;
    }

    /**
     * getQtdNos
     *
     * @return int, qtde de nos na lista ligada
     */
    public int getQtdNos(){
        return this.qtdNos;
    }

    /**
     * setQtdNos
     *
     * @param qtdNos Um parâmetro
     */
    private void setQtdNos(int qtdNos){
        this.qtdNos = qtdNos;
    }

    /**
     * estaVazia
     *
     * @return boolean, true se estiver vazia e false caso contrario
     */
    public boolean estaVazia(){
        boolean vazia = false; 
        if (getQtdNos() == 0 && getInicio() == null && getFim() == null){
            vazia = true;
        }
        return vazia;
    }

    /**
     * inserirInicio
     *
     * @param elem Objeto a ser inserido no inicio da lista ligada
     */
    public void inserirInicio(Object elem) {
        No novo = new No(elem); //1
        No aux;
        if (estaVazia()){
            setInicio(novo);
            setFim(novo);
            novo.setProximo(inicio);
        }
        else{
            novo.setProximo(inicio);
            setInicio(novo);
            aux = fim;
            aux.setProximo(inicio);
        }
        setQtdNos(getQtdNos() + 1);
    }

    /**
     * inserirFim
     *
     * @param elem Objeto a ser inserido no fim da lista ligada
     */
    public void inserirFim(Object elem){
        No novo = new No(elem);
        if (estaVazia()){
            setInicio(novo);
            setFim(novo);
            novo.setProximo(inicio);
        }
        else{
            getFim().setProximo(novo);
            setFim(novo);
            novo.setProximo(inicio);
        }
        setQtdNos(getQtdNos() + 1);
    }

    /**
     * removerInicio
     *
     * @return Objeto removido
     */
    public Object removerInicio(){
        No aux = null;
        Object obj = null; 
        if(!estaVazia()){
            if ((getInicio() == getFim())){
                aux = getInicio();
                setInicio(null);
                setFim(null);
            } else {
                aux = getInicio();
                setInicio(aux.getProximo());
                aux.setProximo(null);
            }
            setQtdNos(getQtdNos() - 1);
            obj = aux.getConteudo();
        }

        return(obj);
    }

    /**
     * removerFim
     *
     * @return Objeto removido
     */
    public Object removerFim(){
        No ant = getInicio();
        No aux = null;
        Object obj = null; 
        if (!estaVazia()){
            if ((getInicio() == getFim())){
                aux = getInicio();
                setInicio(null);
                setFim(null);
            } else {            
                // percorre ate achar o no antes do fim
                while(ant.getProximo() != fim){
                    ant = ant.getProximo();
                }
                ant.setProximo(null);
                aux = fim;
                setFim(ant);
            }
            setQtdNos(getQtdNos() - 1);
            obj = aux.getConteudo();           
        }
        return obj;
    }
    
    public Object removerMeio(int n){
        No ant = getInicio();
        No achou;        
        Object obj = null;
        if(!estaVazia()){
            if ((getInicio() == getFim())){
                achou = getInicio();
                setInicio(null);
                setFim(null);
            }
            else{
                if(n == 0)
                    achou = ant;
                else{
                    for(int i = 1;i < n; i++){
                        ant = ant.getProximo();
                    }
                    
                    achou = ant.getProximo();            
                    if(achou == inicio){
                        setInicio(achou.getProximo());
                    }
                    ant.setProximo(achou.getProximo());   
                }
            }
            setQtdNos(getQtdNos() - 1);
            obj = achou.getConteudo(); 
            achou = null;
        }
        return obj;
    }
    
    public String toString(){
        No temp = getInicio();
        String valores = "[";
        int contador = 1;
        if (! estaVazia() ){
            while (contador <= getQtdNos()){ // Pega todos os elementos
                if (temp.getProximo() != inicio)
                    // Separa com virgula
                    valores += temp.getConteudo() + ","; 
                else
                    // O ultimo nao tem virgula
                    valores += temp.getConteudo() + ""; 
                temp = temp.getProximo();
                contador++;
            }
        }
        valores += "]";
        return valores;
    }
}