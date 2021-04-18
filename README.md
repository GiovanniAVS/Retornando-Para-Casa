# Retornando-Para-Casa

# Introdução

O problema apresentado foi uma continuação do enunciado do primeiro trabalho “Extração Z”; neste temos o objetivo de construir um programa que, a partir de diversos métodos, ordena as bases de vários planetas a n-distâncias. No final, os planetas seriam organizados em ordem decrescente de distância.

Para lidar com essa problemática foi feito o Programa “Retornando Para Casa”, este é um software criado com base na linguagem C/C++ que pode realizar a leitura de 3 arquivos.txt predefinidos que contém informações sobre os planetas onde estão localizadas as bases de extração de recurso e as distâncias que eles estão da Terra, em seguida ele ordenará as informações do arquivo selecionado em ordem crescente em um tempo t, dependendo do método de ordenação selecionado.

Para tal programa ser desenvolvido, foi necessário a separação de responsabilidades. O main teve a atribuição de ler os arquivos passados como parâmetro de entrada, criar objetos de alto nível de complexidade e selecionar qual método de ordenação será utilizado. Já o código secundário ordenacao faz a manipulação desses objetos complexos de acordo a necessidade imposta, buscando utilizar as estruturas de dados, sempre que possível, aprendidas até o momento na disciplina Estruturas de Dados. O código terciário planeta é o mais simples dos três, sendo utilizado apenas para atribuição de valores.

# Implementação

O código atual está subdivido em quatro pastas.

• Bin: Contém os arquivos .txt que serão utilizados como entrada do programa e o executável.

• Include: Contém o cabeçalho do código com as classes implementadas.

• Obj: Contém todos arquivos objetos advindos do processo da compilação Makefile.

• Src: Contém as outras implementações utilizadas no código, além do arquivo “main.cpp”, sendo este o arquivo base do programa.

As configurações de hardware e software usados para o desenvolvimento do programa são os seguintes:

    • Sistema Operacional: Windows 10 Home Single Language 
    • Processador: Intel® Core™ i7-7700HQ CPU @ 2.80GHz 2.81GHz
    • Placa de Vídeo: NVIDIA GTX 1050ti 4GB VRAM
    • Memória: 16GB RAM DDR4
    • Memória física: SSD M.2 240GB Leituras: 1.500MB/s e Gravações: 800MB/s 
    • Linguagem: C/C++
    • Compilador: Visual Studio Code + MinGW
    
Para esse programa as principais estruturas de dados utilizada foram as Classes e os vetores dessas Classes, elas estão contidas nos arquivos “planeta.h” e “ordenacao.h”. As funções foram implementadas dentro de três cpps, que são “planeta.cpp”, “ordenacao.cpp”, “main.cpp”. O funcionamento delas será explicado abaixo.

**PLANETA.H:**

• Class Planeta: É responsável por armazenar as variáveis de cada base utilizado, que no caso são o seu nome e a sua distância até a terra em “saltos”. Os seus métodos são simples, e são divididos entre mudar o valor/estado de suas variáveis e obter seu valor/estado.
ORDENACAO.H:

• Class Ordencao: É a principal TAD utilizada para a criação do programa, ela é responsável por implementar todos os métodos de ordenação utilizados durante o programa, não possuindo nenhuma variável, somente funções.
    
• Insertion_sort( ), Merge_sort( ), Quick_sort( ), Comb_sort( ), Quick_sort_mod( ) : São as funções responsáveis por fazer cada tipo de ordenação, cada uma delas, menos a  Insertion_Sort, estão aliadas a funções suportes, que serão citadas abaixo.
    
• merge( ): Com o vetor já dividido várias vezes pela função Merge_sort( ), ele combina dois vetores de forma ordenada em um terceiro auxiliar, depois passa o conteúdo do auxiliar para o vetor original. Esse processo é repetido várias vezes, já que a função Merge_sort( ) é recursiva. Por não alterar a ordem de elementos iguais, ela é considerada estável.
    
• particao( ): Serve para organizar o vetor a partir de um pivô dado pela função Quick_sort( ), nesta subdivisão, os elementos menos que o pivô ficaram a esquerda e os maiores a direita. Ela retorna o último elemento que estava a direita do pivô e foi trocado. Por alterar a ordem de elementos iguais, ela é considerada não estável.

• get_gap( ): A função Comb_sort( ) necessita de um valor de encolhimento para funcionar, está função retorna esse valor gap, a cada chamada dessa função esse valor é reduzido em 1.3 vezes.

• particao_mod( ): É bastante similar a função particao( ), entretanto neste caso são feitas 3 subdivisões, uma com os valores menores que o pivô, uma com os valores iguais ao pivô e uma com os valores maiores que o pivô.
      

**MAIN.CPP:**

• Ela é responsável pela verificação da integridade dos arquivos .txt de entrada, ademais é por meio dela que é decidido qual algoritmo será utilizado e o seu tempo de execução.
      
# Instruções de compilação e execução

**OBS1:** As instruções dadas a seguir são para compilar o programa no sistema operacional Windows 10.

**OBS2:** O método de ordenação que está sendo utilizado atualmente é o Quick Sort modificado, caso queria mudar para outro, é necessário abrir o arquivo main.cpp na pasta “bin”, comentar a linha 53 “ord.Quick_sort_mod(array_de_planetas, 0, nlinhas-1);” utilizando “//” antes do termo e retirar o comentário do método que deseja utilizar.

Para a execução do processo de compilação é necessário que navegue para a pasta em que o projeto está localizado. Primeiramente, caso seja feita alguma modificação dos arquivos .cpp ou .h é necessário refazer o Makefile do projeto, para isso é só executar no terminal o comando “make”. 

O executável do programa já estará pronto dentro da pasta “bin”, então para utilizá-lo é necessário saber o diretório do arquivo, após obtido um endereço que se parece com <C:\Users\Desktop\tp1\bin> copie toda a parte depois de “Users”, chame o seu prompt de comando, digite “cd” e em seguida cole o endereço copiado, por último é só digitar “run.out” “nome do arquivo que deseja ler.txt” “quantidade de linhas que serão lidas” que o programa rodará. 
Exemplo: run.out dados.txt 1000
