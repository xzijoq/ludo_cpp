;;; package --- Summary
;;; Commentary:
;;; Code:

(package-initialize)




(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(custom-enabled-themes '(dracula))
 '(custom-safe-themes
   '("dcdd1471fde79899ae47152d090e3551b889edf4b46f00df36d653adc2bf550d" default))
 '(eldoc-echo-area-use-multiline-p nil)
 '(lsp-ui-doc-alignment 'window)
 '(lsp-ui-doc-max-height 3)
 '(lsp-ui-doc-use-webkit nil)
 '(package-archives
   '(("gnu" . "https://elpa.gnu.org/packages/")
     ("melpa" . "https://melpa.org/packages/")))
 '(package-selected-packages
   '(omnisharp gdscript-mode origami rainbow-delimiters eglot nasm-mode clang-format cmake-mode company-lsp lsp-ivy lsp-treemacs lsp-ui lsp-mode treemacs-icons-dired treemacs-projectile treemacs yasnippet flycheck company-box company counsel org-bullets which-key dracula-theme use-package)))
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

