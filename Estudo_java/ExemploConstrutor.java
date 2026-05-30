/**
 * Tutorial: Como utilizar Construtores em Java
 * 
 * O que é um Construtor?
 * - É um método especial usado para inicializar objetos
 * - Tem o mesmo nome da classe
 * - Não tem tipo de retorno (nem void)
 * - É chamado automaticamente quando criamos um objeto com "new"
 */

public class ExemploConstrutor {
    
    // Atributos da classe
    private String nome;
    private int idade;
    private double altura;
    
    // ============================================
    // CONSTRUTOR 1: Construtor Padrão (sem parâmetros)
    // ============================================
    public ExemploConstrutor() {
        this.nome = "Sem nome";
        this.idade = 0;
        this.altura = 0.0;
        System.out.println("Construtor padrão chamado!");
    }
    
    // ============================================
    // CONSTRUTOR 2: Construtor com parâmetros (sobrecarga)
    // ============================================
    public ExemploConstrutor(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
        this.altura = 0.0; // valor padrão
        System.out.println("Construtor com 2 parâmetros chamado!");
    }
    
    // ============================================
    // CONSTRUTOR 3: Construtor com todos os parâmetros
    // ============================================
    public ExemploConstrutor(String nome, int idade, double altura) {
        this.nome = nome;
        this.idade = idade;
        this.altura = altura;
        System.out.println("Construtor com 3 parâmetros chamado!");
    }
    
    // ============================================
    // GETTERS e SETTERS
    // ============================================
    public String getNome() {
        return nome;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public int getIdade() {
        return idade;
    }
    
    public void setIdade(int idade) {
        this.idade = idade;
    }
    
    public double getAltura() {
        return altura;
    }
    
    public void setAltura(double altura) {
        this.altura = altura;
    }
    
    // ============================================
    // Método para exibir informações
    // ============================================
    public void exibirInfo() {
        System.out.println("Nome: " + nome);
        System.out.println("Idade: " + idade + " anos");
        System.out.println("Altura: " + altura + "m");
    }
    
    // ============================================
    // Método MAIN - Demonstrando o uso dos construtores
    // ============================================
    public static void main(String[] args) {
        System.out.println("=== Demonstrando Construtores em Java ===\n");
        
        // 1. Usando o construtor padrão
        System.out.println("--- Criando objeto com construtor padrão ---");
        ExemploConstrutor pessoa1 = new ExemploConstrutor();
        pessoa1.exibirInfo();
        
        System.out.println();
        
        // 2. Usando construtor com 2 parâmetros
        System.out.println("--- Criando objeto com construtor (nome, idade) ---");
        ExemploConstrutor pessoa2 = new ExemploConstrutor("Maria", 25);
        pessoa2.exibirInfo();
        
        System.out.println();
        
        // 3. Usando construtor com 3 parâmetros
        System.out.println("--- Criando objeto com construtor (nome, idade, altura) ---");
        ExemploConstrutor pessoa3 = new ExemploConstrutor("João", 30, 1.75);
        pessoa3.exibirInfo();
        
        System.out.println();
        
        // 4. Modificando valores com setters
        System.out.println("--- Modificando pessoa1 com setters ---");
        pessoa1.setNome("Pedro");
        pessoa1.setIdade(22);
        pessoa1.setAltura(1.80);
        pessoa1.exibirInfo();
    }
}

/**
 * RESUMO - CONSTRUTORES EM JAVA:
 * 
 * 1. O que fazem:
 *    - Inicializam objetos quando são criados
 *    - Alocam memória para o objeto
 *    - Podem validar dados
 * 
 * 2. Características:
 *    - Mesmo nome da classe
 *    - Sem tipo de retorno
 *    - Podem existir múltiplos construtores (sobrecarga)
 *    - Se não definir nenhum, Java cria um padrão
 * 
 * 3. Palavra-chave "this":
 *    - Diferencia atributos de parâmetros com mesmo nome
 *    - this.atributo = parâmetro
 * 
 * 4. Exemplo de uso:
 *    - new Classe()           → Construtor padrão
 *    - new Classe(param)      → Construtor correspondente
 */

