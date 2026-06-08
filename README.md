# ZoneTrans

Ferramenta simples para teste de transferência de zona DNS (AXFR), desenvolvida em C para fins de estudo e aprendizado.

> ⚠️ Este projeto foi criado apenas para fins educacionais e testes autorizados. Não utilize em ambientes ou alvos sem permissão.

## Sobre

O **ZoneTrans** é uma ferramenta simples que realiza:

* Descoberta de servidores DNS autoritativos (NS);
* Tentativa de transferência de zona (AXFR);
* Exibição completa dos registros retornados;
* Saída organizada diretamente no terminal.

O objetivo do projeto foi praticar:

* Programação em C;
* Manipulação de processos com `popen()`;
* Processamento de saída de comandos;
* Conceitos básicos de DNS e Zone Transfer.

## Exemplo de uso

```bash
./zonetrans dominio.com
```

## Exemplo de saída

<img width="986" height="683" alt="image" src="https://github.com/user-attachments/assets/2e3530f6-db66-42ed-85e0-acd006baa729" />


## Compilação

```bash
gcc zonetrans.c -o zonetrans
```

## Dependências

O projeto utiliza ferramentas presentes na maioria das distribuições Linux:

* dig
* host
* gcc

Em sistemas baseados em Debian:

```bash
sudo apt install dnsutils gcc
```

## Aviso

Esta ferramenta é extremamente simples e foi desenvolvida por um iniciante como forma de aprendizado.

Não possui todos os recursos encontrados em ferramentas profissionais como:

* dnsrecon
* amass
* fierce

O código pode conter limitações, erros ou abordagens que podem ser melhoradas futuramente.

Contribuições, sugestões e feedbacks são sempre bem-vindos.

## Agradecimentos

Agradecimento especial à comunidade da **Desec Security** pela base de conhecimento e pelos conteúdos compartilhados que serviram como inspiração para este projeto.

## Autor

**igr0t**

GitHub: https://github.com/igr0t

## Licença

Este projeto é distribuído apenas para fins educacionais.
