$(document).ready(function(){
	$("#submit").click( upload );
	$("#search").click( search );
	$("#myBar").progressbar({
      value: 37
    });

});
function upload(){
	var formData = new FormData();
	var file = $("#file")[0].files[0];
	formData.append("file", file);
	$.ajax({
		method : "POST",
		data : formData,
		url : "php/udp.php",
		contentType: false,
    	processData: false,
    	success : function( response ){
    		console.log( response );
    		var json = JSON.parse( response );
    		if( json.status == "1" ){
    			console.log("OK");
    		}else if( json.staus == "-1"){
    			console.log("NOT OK");
    		}
    	}
	});
}
function search(){
	var cad = $("#cad").val();
	$.ajax({
		method : "POST",
		url : "php/Envia.php",
		data : {
			"cadena" : cad
		},
		success : function( response ){
    		console.log( response );
    		var json = JSON.parse( response );
    		if( json.status == "1" ){
    			console.log("OK");
    		}else if( json.staus == "-1"){
    			console.log("NOT OK");
    		}
		}
	});
}