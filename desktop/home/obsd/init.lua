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


-- Space as leader key
--vim.g.mapleader = '/'

-- ======================================================================

vim.keymap.set('n', '<leader>w', '<cmd>write<cr>', {desc = 'Save'})

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
	{'nvim-tree/nvim-web-devicons'},
	{'akinsho/bufferline.nvim'},
	{'nvim-tree/nvim-tree.lua'},
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


vim.keymap.set('n', '<leader>t', '<cmd>NvimTreeToggle<cr>')
