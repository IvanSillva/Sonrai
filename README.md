SONRAI

Desenvolvido por:

Ivan Batista da Silva
Jorge Confessor de Moura Junior
Vitoria Maria Lucio Deon  
	
Programa desenvolvido em linguagem C++ para criar um sistema de gerenciamento de banco de dados. Com o intuito de servir como atividade avaliativa na disciplina de Linguagem de Programação I alocada ao Curso de Bacharelado em T.I. lotado no Instituto Metropóle Digital. Todas as funcionalidades pedidas no documento foram implementadas, além delas implementamos uma função extra em que o usuário pode abrir a sua tabela no libreofice direto do terminal e visualizá-la no programa.  


Modo de uso

	Abra o terminal na pasta do projeto e digite o seguinte:

	$ g++ startup.cpp
	
	Para inicialização, digite o seguinte comando:

	$ ./a.out

Funções disponíveis

	1. Criar Tabela (Feito por Ivan,Jorge e Vitoria)

	2. Listagem das Tabelas criadas (Feito por Ivan,Jorge e Vitoria)

	3. Adicionar linha (Feito por Ivan,Jorge e Vitoria)

	4. Listar dados (Feito por Ivan,Jorge e Vitoria)

	5. Pesquisa de dados (Feito por Ivan,Jorge e Vitoria)

	  5.1 - Valores maior que o valor informado (Feito por Ivan,Jorge e Vitoria) 
	  5.2 - Valores maior ou igual que o valor informado (Feito por Ivan,Jorge e Vitoria) 
	  5.3 - Valores igual o valor informado (Feito por Ivan,Jorge e Vitoria) 
	  5.4 - Valores menor que o valor informado (Feito por Ivan,Jorge e Vitoria) 
	  5.5 - Valores menor ou igual que o valor informado (Feito por Ivan,Jorge e Vitoria) 
	  5.6 - Valores próximo ao valor informado (Feito por Jorge)
	 
	6. Apagar valor (Feito por Ivan,Jorge e Vitoria)

	7. Apagar Tabelas (Feito por Ivan,Jorge e Vitoria)

	Ao implementar a função de deletar valores da tabela, optamos por utilizar o método de criar um novo arquivo, passar as informações para esse novo arquivo sem a informação da linha que o usuário gostaria de deletar, e renomear esse novo arquivo com mesmo nome do original. Dessa forma entedemos que há uma forma mais simples de implementar isso, como por exemplo, fazer a alteração no mesmo arquivo sem a necessidade da criação de outro e salva-lo, deixando o codigo mais limpo e programa mais rápido e leve. 

