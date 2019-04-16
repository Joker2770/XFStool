<!-- index.html -->

'use strict';

//new_element = document.createElement("script");
//new_element.setAttribute("type","text/javascript");
//new_element.setAttribute("src", "parameter.js");
//document.body.appendChild(new_element);

function output(message) {
	var myDate = new Date();
	var mytime=myDate.toLocaleTimeString();     //获取当前时间
    var output = document.getElementById("output");
    output.innerHTML = output.innerHTML + mytime + " >> " + message + "\n";
}
			
var wsUri = "ws://localhost:12345";
window.onload = function() {
	var socket = new WebSocket(wsUri);

	socket.onclose = function() {
		console.error("web channel closed");
	};

	socket.onerror = function(error) {
		console.error("web channel error: " + error);
	};

	socket.onopen = function() {
		new QWebChannel(socket, function(channel) {
			
            // make DataExchange object accessible globally
            window.DataExchange = channel.objects.DataExchange;
			window.DataExchange.cppToJs.connect(function (msg) {output(msg);});
			var a = new Object()
			a.dwVersionsRequired = 16908035;
			var sMethod = "WFSStartUp";
			window.DataExchange.jsToCpp(sMethod, JSON.stringify(a));
			var sMethod = "WFSCleanUp";
			window.DataExchange.jsToCpp(sMethod, "");
		});
	}
}