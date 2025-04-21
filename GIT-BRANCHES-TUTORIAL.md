# 📘 Guia de Uso de Branches no GitHub

## 🔧 CONFIGURAÇÃO INICIAL (Feita uma vez)

1. **Clone o repositório**
   ```bash
   git clone https://github.com/usuario/repositorio.git
   cd repositorio
   ```

2. **Configure seu nome e e-mail (se ainda não fez)**
   ```bash
   git config user.name "Seu Nome"
   git config user.email "seu@email.com"
   ```

---

## 🧑‍💻 CRIANDO SUA BRANCH PESSOAL

1. **Atualize a branch `main` local**
   ```bash
   git checkout main
   git pull origin main
   ```

2. **Crie e troque para sua branch pessoal**
   ```bash
   git checkout -b sua-branch
   ```

3. **Suba sua branch para o GitHub**
   ```bash
   git push -u origin sua-branch
   ```

---

## ✍️ TRABALHANDO NA SUA BRANCH

1. Faça alterações no código.

2. Adicione e commite:
   ```bash
   git add .
   git commit -m "Mensagem do que foi feito"
   ```

3. Suba para o GitHub:
   ```bash
   git push
   ```

---

## 🔄 ANTES DE DAR MERGE NA MAIN

1. Volte para a `main` e atualize:
   ```bash
   git checkout main
   git pull origin main
   ```

2. Volte para sua branch:
   ```bash
   git checkout sua-branch
   ```

3. Mescle a `main` atualizada na sua branch:
   ```bash
   git merge main
   ```

4. Resolva conflitos (se houver), adicione e commite:
   ```bash
   git add .
   git commit -m "Resolvendo conflitos com main"
   ```

5. Suba novamente:
   ```bash
   git push
   ```

---

## ✅ MERGE FINAL NA MAIN

1. No **GitHub**, vá na sua branch e clique em **"Compare & pull request"**.

2. Verifique se está tudo certo e crie o **Pull Request (PR)**.

3. Após aprovação, clique em **"Merge pull request"**.

4. (Opcional) Apague a branch no GitHub se não for mais usar.

---

## 🔄 DICAS PARA MANTER TUDO ATUALIZADO

Sempre que for começar a trabalhar:
```bash
git checkout main
git pull origin main
git checkout sua-branch
git merge main
```