$(document).ready(function () {
  $('#groups-add').click(function() {
    $('#myModal').on('shown.bs.modal', function () {
      $("#myModalLabel").text("Add Group")
      $("#modal-body").html('<div class="form-group"><label for="group-name">Group Name</label><input type="text" class="form-control" id="group-name" placeholder="Group Name"></div>')
    })

    $('#myModal').on('hide.bs.modal', function () {
      console.log("Add group closed.")
    })

    $('#myModal #action-confirm').click(function (){
      console.log("Add group confirmed")
      console.log($('#group-name').val())

      $('#myModal').modal('hide')
    })
  })
});
