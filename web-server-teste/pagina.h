const char pagina[] = R"=====(<!DOCTYPE html>
<html lang="pt-BR">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>web-server-ESP8266</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@400;500&display=swap" rel="stylesheet">
    <style>
        *{
            margin:0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Poppins', sans-serif;
        }
        body{
            background-color:gray;
        }
        header{
            width: 100%;
            background-color: black;
            display: flex;
            align-items: center;
        }
        header .logo img{
            width: 100%;
            max-width: 300px;
        }
        header .title {
            color: white;
            font-size: 20px;
        }
        .container{
            width: 100%;
            max-width: 1300px;
            margin: 0 auto;
            display: flex;
        }
        section{
            background-color: black;
            padding: 20px;
        }
        section .item-head{
            display: flex;
            justify-content: space-between;
            align-items: center;
        }
        section .titulo{
            color: white;
            font-size: 20px;
        }
        section .estado{
            font-size: 13px;
            padding: 2px;
            text-transform: uppercase;
        }
        .on{
            background-color: green;
            color: white;
        }
        .off{
            background-color: red;
            color: white;
        }
        section .actions{
            width: 100%;
            padding-top: 20px;
            display: flex;
            justify-content: space-between;
        }
        section .actions .ligar{
            width: 50%;
            height: 40px;
            background-color: green;
            color: white;
            justify-content: center;
            align-items: center;
            text-decoration:none;
            text-transform: uppercase;
            display: flex;
            margin-right: 10px;
            transition: all 0.2s;
        }
        section .actions .desligar{
            width: 50%;
            height: 40px;
            background-color: red;
            color: white;
            justify-content: center;
            align-items: center;
            text-decoration:none;
            text-transform: uppercase;
            display: flex;
            transition: all 0.2s;
        }
        section .actions .ligar:hover{
            background-color: #0d7425;
        }
        section .actions .desligar:hover{
            background-color: #dc3545;
        }
        /*Responsividade*/
        /*Desktop*/
        @media(min-width:700px){
            header{
                justify-content: space-between;
                padding: 20px 60px 20px 60px;
            }
            .container{
                justify-content: center;
                padding: 20px 40px 20px 40px;
                flex-wrap: wrap;
            }
            section{
                width: 30%;
                margin: 20px;
            }
            footer{
                position: absolute;
                bottom: 0;
                padding: 0 10px 10px 0;
                width: 100%;
                text-align: center;
            }
        }
        /*Mobile*/
        @media(max-width:700px){
            header{
            justify-content: center;
            flex-direction: column;
            align-items: center;
            padding: 30px 10px 20px 10px;
            }
            header .title{
                margin-top: 10px;
            }
            .container{
                padding: 20px;
                flex-direction: column;
            }
            section{
                width: 100%;
                margin: 20px;
                margin-right: 20px;
            }
            footer{
                margin-top: 20px;
                width: 100%;
                text-align: center;
                margin-bottom: 40px;
            }
        }
    </style>
</head>
<body>
    <header>
        <div class="logo">
            <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRcYHPbrZNEVo1MqsIefiXuGjbfFKkOhVBdScJeYO0kJu11_l5-QcFRjBUjg8psZG1rrA8&usqp=CAU" alt="Testando web-server" />
        </div>
        <div class="title">Web - Server ESP8266</div>
    </header>
    <div class="container">
    )=====";
 const char rodape[] = R"=====(</div>
    <footer>
    Por Emilly Lamotte
    </footer>
</body>
</html>)=====";


