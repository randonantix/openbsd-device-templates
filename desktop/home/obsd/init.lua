-- https://vonheikemen.github.io/devlog/tools/build-your-first-lua-config-for-neovim/
-- https://vonheikemen.github.io/devlog/tools/neovim-plugins-to-get-started/
-- https://github.com/VonHeikemen/nvim-starter/blob/02-opinionated/init.lua
vim.opt.number = true
vim.opt.mouse = 'a'
vim.opt.ignorecase = true
vim.opt.smartcase = true
vim.opt.tabstop = 2
-- vim.opt.hlseach = false
vim.opt.wrap = true
vim.opt.breakindent = true
vim.opt.shiftwidth = 2
vim.opt.expandtab = false
vim.opt.autowrite = true

-- Use Ctrl-n for basic autocomplete. Ctrl-x,Ctrl-o is supposed to bring up omnicomplete
-- see also universal-ctags package
vim.opt.tags = '/home/obsd/.config/nvim/system.tags,tags'
vim.opt.omnifunc = 'ccomplete#Complete'
vim.opt.confirm = true


-- Space as leader key
--vim.g.mapleader = '/'

-- ======================================================================

vim.keymap.set('n', '<leader>w', '<cmd>write<cr>', {desc = 'Save'})
-- save file
vim.keymap.set({ "i", "x", "n", "s" }, "<C-s>", "<cmd>w<cr><esc>", { desc = "Save File" })

-- better indenting
vim.keymap.set("v", "<", "<gv")
vim.keymap.set("v", ">", ">gv")

-- commenting
vim.keymap.set("v", "/", "<cmd>normal gcc<cr>")
-- vim.keymap.set("v", "<leader>/", "0x")

vim.keymap.set("n", "<leader>\\", "I<esc><cmd>normal gcc<cr>", { desc = "Comment current line" })
vim.keymap.set("n", "<leader>o", "o<esc>Vcx<esc><cmd>normal gcc<cr>fxa<bs>", { desc = "Add Comment Below" })
vim.keymap.set("n", "<leader>O", "O<esc>Vcx<esc><cmd>normal gcc<cr>fxa<bs>", { desc = "Add Comment Above" })

vim.keymap.set("n", "gco", "o<esc>Vcx<esc><cmd>normal gcc<cr>fxa<bs>", { desc = "Add Comment Below" })
vim.keymap.set("n", "gcO", "O<esc>Vcx<esc><cmd>normal gcc<cr>fxa<bs>", { desc = "Add Comment Above" })

-- go-vim
vim.keymap.set("n", "<C-n>", ":cnext<CR>", { desc = "Go to next error in GoBuild", remap = true })
vim.keymap.set("n", "<C-m>", ":cprevious<CR>", { desc = "Go to previous error in GoBuild", remap = true })
vim.keymap.set('n', '<leader>a', ':cclose<CR>', { desc = 'Close', remap = false})
vim.keymap.set('n', '<leader>b', '<Plug>(go-build)', { desc = ':GoBuild', remap = true})
vim.keymap.set('n', '<leader>r', '<Plug>(go-run)', { desc = ':GoRun', remap = true})

-- ======================================================================

local lazy = {}

function lazy.install(path)
  if not vim.loop.fs_stat(path) then
    print('Installing lazy.nvim....')
    vim.fn.system({
      'git',
      'clone',
      '--filter=blob:none',
      'https://github.com/folke/lazy.nvim.git',
      '--branch=stable', -- latest stable release
      path,
    })
  end
end

function lazy.setup(plugins)
  if vim.g.plugins_ready then
    return
  end

  -- You can "comment out" the line below after lazy.nvim is installed
  lazy.install(lazy.path)

  vim.opt.rtp:prepend(lazy.path)

  require('lazy').setup(plugins, lazy.opts)
  vim.g.plugins_ready = true
end

lazy.path = vim.fn.stdpath('data') .. '/lazy/lazy.nvim'
lazy.opts = {}

lazy.setup({
	{'nvim-lualine/lualine.nvim'},
	{'folke/tokyonight.nvim'},
	{'folke/which-key.nvim'},
	{'nvim-tree/nvim-web-devicons'},
	{'akinsho/bufferline.nvim'},
	{'nvim-tree/nvim-tree.lua'},
  {'terrortylor/nvim-comment'},
	{'fatih/vim-go'},
	-- {'Shougo/neocomplete.vim'},
	{'Shougo/deoplete.nvim'},
	-- {'junegunn/fzf'},
	{'majutsushi/tagbar'},
})


-- ========================================================================== --
-- ==                         PLUGIN CONFIGURATION                         == --
-- ========================================================================== --

---
-- Colorscheme
---
-- vim.opt.termguicolors = true
-- vim.cmd.colorscheme('tokyonight')

---
-- lualine.nvim (statusline)
---
vim.opt.showmode = false

-- See :help lualine.txt
require('lualine').setup({
  options = {
    theme = 'tokyonight',
    icons_enabled = true,
    component_separators = '|',
    section_separators = '',
    disabled_filetypes = {
      statusline = {'NvimTree'}
    }
  },
})

---
-- bufferline
---
-- See :help bufferline-settings
require('bufferline').setup({
  options = {
    mode = 'buffers',
    offsets = {
      {filetype = 'NvimTree'}
    },
  },
  -- :help bufferline-highlights
  highlights = {
    buffer_selected = {
      italic = false
    },
    indicator_selected = {
      fg = {attribute = 'fg', highlight = 'Function'},
      italic = false
    }
  }
})


require("nvim-tree").setup()
require('nvim_comment').setup()

vim.keymap.set('n', '<leader>t', '<cmd>NvimTreeToggle<cr>')

local wk = require("which-key")
wk.add({
  {
		mode = { "n", "v" }, -- NORMAL and VISUAL mode
    { "<leader>q", "<cmd>q<cr>", desc = "Quit" }, -- no need to specify mode since it's inherited
    { "<leader>w", "<cmd>w<cr>", desc = "Write" },
	}
})
