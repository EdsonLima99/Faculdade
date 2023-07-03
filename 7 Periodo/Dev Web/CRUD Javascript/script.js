document.getElementById('contact-form').addEventListener('submit', function(event) {
  event.preventDefault();

  var name = document.getElementById('name').value;
  var phone = document.getElementById('phone').value;
  var email = document.getElementById('email').value;

  if (name && phone && email) {
    var table = document.getElementById('contact-table');
    var row = table.insertRow(-1);

    var nameCell = row.insertCell(0);
    nameCell.textContent = name;

    var phoneCell = row.insertCell(1);
    phoneCell.textContent = phone;

    var emailCell = row.insertCell(2);
    emailCell.textContent = email;

    var actionsCell = row.insertCell(3);
    var editButton = document.createElement('button');
    editButton.textContent = 'Editar';
    editButton.addEventListener('click', function() {
      editRow(row);
    });
    actionsCell.appendChild(editButton);

    var deleteButton = document.createElement('button');
    deleteButton.textContent = 'Excluir';
    deleteButton.addEventListener('click', function() {
      if (confirm('Tem certeza de que deseja excluir este contato?')) {
        deleteRow(row);
      }
    });
    actionsCell.appendChild(deleteButton);

    clearForm();
  }
});

function editRow(row) {
  var name = row.cells[0].textContent;
  var phone = row.cells[1].textContent;
  var email = row.cells[2].textContent;

  row.innerHTML = `
    <td><input type="text" value="${name}" required></td>
    <td><input type="text" value="${phone}" required></td>
    <td><input type="email" value="${email}" required></td>
    <td class="actions">
      <button class="save-button">Salvar</button>
      <button class="cancel-button">Cancelar</button>
    </td>
  `;

  var saveButton = row.querySelector('.save-button');
  saveButton.addEventListener('click', function() {
    saveEdit(row);
  });

  var cancelButton = row.querySelector('.cancel-button');
  cancelButton.addEventListener('click', function() {
    cancelEdit(row, name, phone, email);
  });
}

function saveEdit(row) {
  var nameInput = row.cells[0].querySelector('input');
  var phoneInput = row.cells[1].querySelector('input');
  var emailInput = row.cells[2].querySelector('input');

  var newName = nameInput.value;
  var newPhone = phoneInput.value;
  var newEmail = emailInput.value;

  if (newName && newPhone && newEmail) {
    row.cells[0].textContent = newName;
    row.cells[1].textContent = newPhone;
    row.cells[2].textContent = newEmail;

    var actionsCell = row.cells[3];
    actionsCell.innerHTML = '';

    var editButton = document.createElement('button');
    editButton.textContent = 'Editar';
    editButton.addEventListener('click', function() {
      editRow(row);
    });
    actionsCell.appendChild(editButton);

    var deleteButton = document.createElement('button');
    deleteButton.textContent = 'Excluir';
    deleteButton.addEventListener('click', function() {
      if (confirm('Tem certeza de que deseja excluir este contato?')) {
        deleteRow(row);
      }
    });
    actionsCell.appendChild(deleteButton);
  }
}

function cancelEdit(row, name, phone, email) {
  row.cells[0].textContent = name;
  row.cells[1].textContent = phone;
  row.cells[2].textContent = email;

  var actionsCell = row.cells[3];
  actionsCell.innerHTML = '';

  var editButton = document.createElement('button');
  editButton.textContent = 'Editar';
  editButton.addEventListener('click', function() {
    editRow(row);
  });
  actionsCell.appendChild(editButton);

  var deleteButton = document.createElement('button');
  deleteButton.textContent = 'Excluir';
  deleteButton.addEventListener('click', function() {
    if (confirm('Tem certeza de que deseja excluir este contato?')) {
      deleteRow(row);
    }
  });
  actionsCell.appendChild(deleteButton);
}

function deleteRow(row) {
  var table = document.getElementById('contact-table');
  table.deleteRow(row.rowIndex);
}

function clearForm() {
  document.getElementById('name').value = '';
  document.getElementById('phone').value = '';
  document.getElementById('email').value = '';
}
