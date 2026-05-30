import json
import os


class Pokedex:
    def __init__(self, id, nome, tipo, nivel):
        self.id = id
        self.nome = nome
        self.tipo = tipo
        self.nivel = nivel

    def __str__(self):
        return f"{self.id} - {self.nome} | Tipo: {self.tipo} | Nivel: {self.nivel}"


vetorPokes = []

def removerPoke():

    if len(vetorPokes) == 0:
        print("Nenhum Pokémon cadastrado.")
        return

    while True:
        try:
            id_remover = int(input("Digite o ID do Pokémon que deseja remover: "))
        except ValueError:
            print("ID inválido. Tente novamente.")
            continue

        encontrado = False

        for i in range(len(vetorPokes)):

            if vetorPokes[i].id == id_remover:

                del vetorPokes[i]
                encontrado = True

                # reorganiza os IDs
                for j in range(len(vetorPokes)):
                    vetorPokes[j].id = j + 1

                print("Pokémon removido com sucesso!")
                return

        if not encontrado:
            print("ID não encontrado. Tente novamente.")

def atualizarPoke():

    if len(vetorPokes) == 0:
        print("Nenhum Pokémon cadastrado.")
        return

    while True:

        try:
            id_busca = int(input("Digite o ID do Pokémon que deseja atualizar: "))
        except ValueError:
            print("ID inválido. Tente novamente.")
            continue

        encontrado = False

        for pokemon in vetorPokes:

            if pokemon.id == id_busca:
                encontrado = True

                print("\nPokémon encontrado:")
                print(pokemon)

                novo_nome = input("Novo nome (Enter para manter): ").strip()
                if novo_nome != "":
                    pokemon.nome = novo_nome

                novo_tipo = input("Novo tipo (separe por vírgula / Enter para manter): ").strip()
                if novo_tipo != "":
                    pokemon.tipo = [t.strip() for t in novo_tipo.split(",")]

                while True:
                    novo_nivel = input("Novo nível (Enter para manter): ").strip()

                    if novo_nivel == "":
                        break

                    try:
                        novo_nivel = int(novo_nivel)

                        if 1 <= novo_nivel <= 100:
                            pokemon.nivel = novo_nivel
                            break
                        else:
                            print("Digite nível entre 1 e 100.")

                    except ValueError:
                        print("Digite um número válido.")

                print("\nPokémon atualizado com sucesso!")
                return

        if not encontrado:
            print("ID não encontrado. Tente novamente.")

def mostrarPoke():

    if len(vetorPokes) == 0:
        print("Nenhum Pokémon cadastrado.")
        return

    print("\n--- LISTA DE POKÉMONS ---")

    for pokemon in vetorPokes:
        print("\n",pokemon)

def adicionarPoke():
    id = len(vetorPokes) + 1

    while True:
        nome = input("Nome: ").strip()
        if nome != "":
            break
        print("Nome inválido.")

    while True:
        entrada = input("Tipos do Pokémon (separe por vírgula): ").strip()
        if entrada != "":
            tipos = entrada.split(",")
            tipos = [t.strip() for t in tipos]
            break
        print("Tipo inválido.")

    while True:
        try:
            nivel = int(input("Nível do Pokémon: "))
            if 1 <= nivel <= 100:
                break
            print("Digite nível entre 1 e 100.")
        except ValueError:
            print("Digite um número válido.")

    novo = Pokedex(id, nome, tipos, nivel)
    vetorPokes.append(novo)

    print("Pokémon adicionado com sucesso!")

def salvarJSON():

    dados = []

    for pokemon in vetorPokes:
        dados.append({
            "id": pokemon.id,
            "nome": pokemon.nome,
            "tipo": pokemon.tipo,
            "nivel": pokemon.nivel
        })

    with open("pokedex.json", "w", encoding="utf-8") as arquivo:
        json.dump(dados, arquivo, indent=4, ensure_ascii=False)

def carregarJSON():

    if not os.path.exists("pokedex.json"):
        return

    with open("pokedex.json", "r", encoding="utf-8") as arquivo:
        dados = json.load(arquivo)

    for item in dados:
        pokemon = Pokedex(
            item["id"],
            item["nome"],
            item["tipo"],
            item["nivel"]
        )
        vetorPokes.append(pokemon)

def menu():

    while True:

        print("\n1 - Adicionar")
        print("2 - Listar")
        print("3 - Atualizar")
        print("4 - Remover")
        print("5 - Carregar Dados")
        print("6 - Sair")

        op = input("Escolha: ")

        if op == "1":
            adicionarPoke()
            salvarJSON()

        elif op == "2":
            mostrarPoke()

        elif op == "3":
            atualizarPoke()
            salvarJSON()

        elif op == "4":
            removerPoke()
            salvarJSON()

        elif op == "5":
            carregarJSON()
            print("Dados carregados com sucesso!")

        elif op == "6":
            print("Saindo...")
            break

        else:
            print("Opção inválida.")


# main do phytonkkkk

menu()
