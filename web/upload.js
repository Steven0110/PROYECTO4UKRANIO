$(document).ready(function(){
	$("#submit").click( upload );
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
		url : "uploader.php",
		contentType: false,
    	processData: false,
    	beforeSend : function( response ){

    	},
    	success : function( response ){
    		console.log( response );
    	},
    	complete : function( response ){

    	}
	});
}
