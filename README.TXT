Alunos: José Cláudio de Lima Castro e Wilker Sebastian Afonso Pereira

A lógica do raycaster está na classe Raycaster. O processo de renderização é iniciado pelo método render dela,
onde fluxo de interação de um raio é geração do raio onde para cada pixel da imagem, o método generateRay é chamado. 
Ele cria um Ray3f no espaço do mundo, começando na posição da câmara e apontando na direção do centro desse pixel, o raio é 
então disparado contra a cena. 
A classe Scene atua como um gestor que contém todos os objetos. A Scene itera por todos os objetos Actor que ela contém. 
Para cada um, ela chama o método virtual intersect(ray) desse ator. O Actor delega a tarefa para o seu componente Shape, 
passando o raio e a sua própria matriz de transformação. 
A classe Shape é a única que realiza o calculo de interseção transformando o raio do espaço do mundo para o seu 
espaço local usando a matriz de transformação inversa. Realizando o teste de interseção nesse espaço local. Se houver um acerto,
ela calcula os detalhes da interseção ponto, normal, distância e retorna o objeto Intersection que contem esses dados.
O Actor recebe o hit da sua Shape. Se a interseção for válida, ele anexa um ponteiro para si mesmo. A Scene recebe os hits de 
todos os atores e retorna apenas o que tiver a menor distância. 
Com isso a classe Raycaster, a verificação de hit passa, e o método shade(scene, ray, hit) é chamado. A função shade usa o 
material do ator para saber qual cor e material para aplicar na iluminação de Phong. Se hit falhar, a cor de fundo é usada.

Obs: foi usado o template, mas o CMakeLists.txt foi alterado pelo Wilker pra funcionar tanto no Windows com msvc quanto no Linux.
