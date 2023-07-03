document.getElementById('formulario-contato').addEventListener('submit', function (event) {
  event.preventDefault();

  var nome = document.getElementById('nome').value;
  var telefone = document.getElementById('telefone').value;
  var email = document.getElementById('email').value;

  if (nome && telefone && email) {
    var tabela = document.getElementById('tabela-contato');
    var row = tabela.insertRow(-1);

    var celulaNome = row.insertCell(0);
    celulaNome.textContent = nome;

    var celulaTelefone = row.insertCell(1);
    celulaTelefone.textContent = telefone;

    var celulaEmail = row.insertCell(2);
    celulaEmail.textContent = email;

    var celulaAcao = row.insertCell(3);
    var botaoEditar = document.createElement('button');
    botaoEditar.className = "botaoEditar";
    botaoEditar.textContent = 'Editar';
    botaoEditar.addEventListener('click', function () {
      editarLinha(row);
    });
    celulaAcao.appendChild(botaoEditar);

    var botaoDeletar = document.createElement('button');
    botaoDeletar.className = "botaoDeletar";
    botaoDeletar.textContent = 'Excluir';
    botaoDeletar.addEventListener('click', function () {
      if (confirm('Tem certeza de que deseja excluir este contato?')) {
        deletarLinha(row);
      }
    });
    celulaAcao.appendChild(botaoDeletar);

    limparFormulario();
  }
});

function editarLinha(row) {
  var nome = row.cells[0].textContent;
  var telefone = row.cells[1].textContent;
  var email = row.cells[2].textContent;

  row.innerHTML = `
    <td><input type="text" value="${nome}" required></td>
    <td><input type="tel" value="${telefone}" required maxlength="11" minlength="10"></td>
    <td><input type="email" value="${email}" required></td>
    <td class="acao">
      <button class="botaoSalvar">Salvar</button>
      <button class="botaoCancelar">Cancelar</button>
    </td>
  `;

  var botaoSalvar = row.querySelector('.botaoSalvar');
  botaoSalvar.addEventListener('click', function () {
    salvarEdicao(row);
  });

  var botaoCancelar = row.querySelector('.botaoCancelar');
  botaoCancelar.addEventListener('click', function () {
    cancelarEdicao(row, nome, telefone, email);
  });
}

function salvarEdicao(row) {
  var nomeInput = row.cells[0].querySelector('input');
  var telefoneInput = row.cells[1].querySelector('input');
  var emailInput = row.cells[2].querySelector('input');

  var novoNome = nomeInput.value;
  var novoTelefone = telefoneInput.value;
  var novoEmail = emailInput.value;

  if (novoNome && novoTelefone && novoEmail) {
    row.cells[0].textContent = novoNome;
    row.cells[1].textContent = novoTelefone;
    row.cells[2].textContent = novoEmail;

    var celulaAcao = row.cells[3];
    celulaAcao.innerHTML = '';

    var botaoEditar = document.createElement('button');
    botaoEditar.className = "botaoEditar";
    botaoEditar.textContent = 'Editar';
    botaoEditar.addEventListener('click', function () {
      editarLinha(row);
    });
    celulaAcao.appendChild(botaoEditar);

    var botaoDeletar = document.createElement('button');
    botaoDeletar.className = "botaoDeletar";
    botaoDeletar.textContent = 'Excluir';
    botaoDeletar.addEventListener('click', function () {
      if (confirm('Tem certeza de que deseja excluir este contato?')) {
        deletarLinha(row);
      }
    });
    celulaAcao.appendChild(botaoDeletar);
  }
}

function cancelarEdicao(row, nome, telefone, email) {
  row.cells[0].textContent = nome;
  row.cells[1].textContent = telefone;
  row.cells[2].textContent = email;

  var celulaAcao = row.cells[3];
  celulaAcao.innerHTML = '';

  var botaoEditar = document.createElement('button');
  botaoEditar.className = "botaoEditar";
  botaoEditar.textContent = 'Editar';
  botaoEditar.addEventListener('click', function () {
    editarLinha(row);
  });
  celulaAcao.appendChild(botaoEditar);

  var botaoDeletar = document.createElement('button');
  botaoDeletar.className = "botaoDeletar";
  botaoDeletar.textContent = 'Excluir';
  botaoDeletar.addEventListener('click', function () {
    if (confirm('Tem certeza de que deseja excluir este contato?')) {
      deletarLinha(row);
    }
  });
  celulaAcao.appendChild(botaoDeletar);
}

function deletarLinha(row) {
  var tabela = document.getElementById('tabela-contato');
  tabela.deleteRow(row.rowIndex);
}

function limparFormulario() {
  document.getElementById('nome').value = '';
  document.getElementById('telefone').value = '';
  document.getElementById('email').value = '';
}