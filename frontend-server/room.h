const char room[] = R"=====(<!DOCTYPE html>
<html lang="pt-BR">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="preconnect" href="https://fonts.gstatic.com">
        <link href="https://fonts.googleapis.com/css2?family=Open+Sans&family=Poppins:wght@500;700&display=swap" rel="stylesheet">
        <script src="https://kit.fontawesome.com/1ab94d0eba.js" crossorigin="anonymous"></script> 
        <script>
            function atualizaRelogio(){ 
            var momentoAtual = new Date();
            var vhora = momentoAtual.getHours();
            var vminuto = momentoAtual.getMinutes();
            var vsegundo = momentoAtual.getSeconds();
            var vdia = momentoAtual.getDate();
            var vmes = momentoAtual.getMonth() + 1;
            var vano = momentoAtual.getFullYear();
            if (vdia < 10){ vdia = "0" + vdia;}
            if (vmes < 10){ vmes = "0" + vmes;}
            if (vhora < 10){ vhora = "0" + vhora;}
            if (vminuto < 10){ vminuto = "0" + vminuto;}
            if (vsegundo < 10){ vsegundo = "0" + vsegundo;}
            dataFormat = vdia + " / " + vmes + " / " + vano;
            horaFormat = vhora + " : " + vminuto + " : " + vsegundo;
            document.getElementById("data").innerHTML = dataFormat;
            document.getElementById("hora").innerHTML = horaFormat;
            setTimeout("atualizaRelogio()",1000);
            }
        </script>
        <script src="https://code.jquery.com/jquery-1.11.2.js"></script>
    <script type="text/javascript">
      jQuery(window).load(function($){
        atualizaRelogio();
      });
    </script>
        <style>
            *{
                box-sizing: border-box;
            }
            body{
                margin: 0;
                font-family: 'Poppins', sans-serif;
                background-color: #808080;
                height: 100vh;
                overflow-y:auto ;
            }
            ul{
                list-style: none;
                display: flex;
                align-items: center;
            }
            li{
                margin: 0 15px;
                color: white;
                font-size: 25px;
                font-weight: 600;
                padding-right: 10px;
            }
            nav{
                display: flex;
                justify-content: space-between;
                margin: 0 30px;
            }
            nav i{
                color: white;
            }
            .logo{
                display: flex;
                align-items: center;
            }
            .logo p{
                padding-left: 30px;
                font-weight: 600;
                color: white;
                font-size: 25px;
            }
            header{
                background-color: #2E2E2E;
                height: 100px;
                align-items: center;
            }
            .room{
                display:flex;
                justify-content: space-around;
                margin-top: 50px;
                align-items: center;
            }
            .leito{
                background-color:#2e2e2e;
                width: 500px;
                height: 250px;
                box-shadow: 1px 3px 18px 4px rgba(0,0,0,0.78);  
            }
            .leito-emergency-on{
                background-color:#2e2e2e;
                width: 500px;
                height: 250px;
                box-shadow: 1px 3px 18px 12px rgba(255,0,0,3.0);
            
                -webkit-animation-name: blinker;
                -webkit-animation-iteration-count: infinite;
                -webkit-animation-timing-function: cubic-bezier(.5, 0, 1, 1);
                -webkit-animation-duration: 0.5s;
            }
            .leito-aux-on{
                background-color:#2e2e2e;
                width: 500px;
                height: 250px;
                box-shadow: 1px 3px 18px 12px rgba(65,105,255,3.0);
            
                -webkit-animation-name: blinker;
                -webkit-animation-iteration-count: infinite;
                -webkit-animation-timing-function: cubic-bezier(.5, 0, 1, 1);
                -webkit-animation-duration: 0.5s;
            }
            .state{
                color: white;
                display: flex;
                align-items: center;
                justify-content: space-around;
                background-color: #2E2E2E;
            }
            .state p{
                padding:15px;
                justify-content: center;  
                align-items: center;
                text-align: center;
                font-size: 25px;
                border-radius: 5px;
                border:2.3px solid #000000;
                width: 180px;
                padding: 12px;
            }
            .state .emergency{
                background-color: #ff0000;
                width: 180px;
            }
            .state .aux{
                background-color: #4169e1;   
                width: 180px;
            }
            @-webkit-keyframes blinker {
                from { opacity: 0.8; }
                to { opacity: 1.0; }
            }
            .item-head{
                display: block;
                text-align: center;
                color: white;
                font-size: 40px;
                justify-content: center;
            }
            footer{
                justify-content:space-between;
                align-items: center;
                display: flex;
                margin-top: 70px;
                height: 100px;
                background-color: #2E2E2E;
                width: 100%;
                position: fixed;
                bottom: 0;
            }
            footer i{
                color: white;
                margin-left: 30px;
                font-size: 25px;
            }
            footer li{
                margin-right: 30px;
            }
    </style>    
        <title>Sistema de Supervisão Hospitalar</title>
    </head>
    <header>
        <nav>
            <div class="logo">
                <a href="http://127.0.0.1:5500/views/home.html">
                    <i class="fas fa-arrow-left fa-3x"></i>
                </a>
                <p class="title">Sistema de Supervisão Hospitalar</p>
            </div>
            <ul>
                <li href="#">Ala: A</li>
                <li href="#">Quarto: 113</li>
                <li href="#">N° de leitos: 6</li>
            </ul>
        </nav>
    </header>
    <body>
       <section class="room"> 
        <div class="leito-emergency-on">
            <h1 class="item-head">Leito 1</h1>
            <div class="state">
                <p class="aux">Auxílio</p>
                <p class="emergency">Emergência</p>
            </div>
        </div>
        <div class="leito">
            <h1 class="item-head">Leito 2</h1>
            <div class="state">
                <p class="aux">Auxílio</p>
                <p class="emergency">Emergência</p>
            </div>
        </div>
        <div class="leito">
            <h1 class="item-head">Leito 3</h1>
            <div class="state">
                <p class="aux">Auxílio</p>
                <p class="emergency">Emergência</p>
            </div>
        </div>
       </section>
       <section class="room"> 
        <div class="leito">
            <h1 class="item-head">Leito 4</h1>
            <div class="state">
                <p class="aux">Auxílio</p>
                <p class="emergency">Emergência</p>
            </div>
        </div>
        <div class="leito">
            <h1 class="item-head">Leito 5</h1>
            <div class="state">
                <p class="aux">Auxílio</p>
                <p class="emergency">Emergência</p>
            </div>
        </div>
        <div class="leito-aux-on">
            <h1 class="item-head">Leito 6</h1>
            <div class="state">
                <p class="aux">Auxílio</p>
                <p class="emergency">Emergência</p>
            </div>
        </div>
       </section>
    </body>
    <footer>
        <i class="fa fa-user-circle-o fa-3x" aria-hidden="true"></i>
        <ul>
            <li id="data"> </li>
            <li>
                <output id="data" ></output>        
                <output id="hora" ></output>  
            </li>
        </ul> 
    </footer>
</html>


)=====";
