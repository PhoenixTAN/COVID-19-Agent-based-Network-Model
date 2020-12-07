# Git workflow 


1. Initially, get the repo
```
$ git clone 
```
2. Write your code locally.

3. Before you submit, you find someone else had pushed something. What do you do?

4. First of all, fetch the changes from the remote repository The changes will store in your local `.git` folder.
    ```
    $ git fetch origin
    ```

    You can use git log to see.
    ```
    $ git log --graph --all
    ```

    You may see the following thing
    ```
    * commit 09745b91e5c59dfd29c5111725f7bb96f0076953 (origin/main, origin/HEAD)
    | Author: PhoenixTAN <tanziqi1756@outlook.com>
    | Date:   Sun Dec 6 21:26:53 2020 -0500
    |
    |     Add more details and collaboration.
    |
    * commit 525c23add6b8184f2b2627d13d4981510b969947 (HEAD -> main)
    | Author: PhoenixTAN <tanziqi1756@outlook.com>
    | Date:   Sun Dec 6 12:01:00 2020 -0500
    |
    |     Initial commit.
    |
    ```
    The `Head` pointer means your local repository. The `origin` pointer means your remote repository.
    `09745b91e5c59dfd29c5111725f7bb96f0076953` is the commit id you will use next. In this case, currently your local repository is 1 commit behind the remote/origin repository. Then, you need to `rebase` your repository on the origin repository.

5. Then, use this command to stash your code locally, which means you temporarily push your change into a stack. 
```
$ git stash
```
Now, you can see your changes disappear. No worries. Use the `git log --graph --all` to see what happened.

6. Rebase your repo on the origin repo.
```
$ git rebase origin-repo-commit-id
```
Use `09745b91e5c59dfd29c5111725f7bb96f0076953` to replace `origin-repo-commit-id`.

Then, use `git log --graph --all`. You can see your `HEAD` pointer has pointed to origin.

7. Pop your changes from stack.
```
$ git stash pop
```

8. Commit and push your change.
```
$ git add .
$ git commit
$ git push
```
