;;; package --- Summary
;;; Commentary:
;;; Code:

(package-initialize)




(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(package-archives
   '(("gnu" . "https://elpa.gnu.org/packages/")
     ("melpa" . "https://melpa.org/packages/")))
 '(package-selected-packages
   '(dracula-theme omnisharp gdscript-mode origami rainbow-delimiters eglot nasm-mode clang-format cmake-mode company-lsp lsp-ivy lsp-mode treemacs-icons-dired treemacs-projectile treemacs yasnippet flycheck company-box company counsel org-bullets which-key use-package)))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )



;; Bootstrap `use-package'
(unless (package-installed-p 'use-package)
  (package-refresh-contents)
  (package-install 'use-package))


;;;LOAD INIT FILE
;;(setq package-check-signature nil)
;(require 'org)
(org-babel-load-file (expand-file-name "~/.emacs.d/myinit.org"))
;;;END INIT

(provide 'init)
;;; init.el ends here

